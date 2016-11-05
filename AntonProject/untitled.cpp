#include "iostream"
#include "string.h"
#include <fstream>
#include <cstdlib>
#include <cstring>

struct AEROFLOT{

	char destination[30];
	int  flightNumber;
	char planeType[30];
};

int menuTitle();

void menu( AEROFLOT *flight, int maxRecord, int countRecords );

AEROFLOT createRecord( AEROFLOT** flight );

void increaseSizeList( AEROFLOT** flight, int * maxRecord, int countRecords );

int enter( AEROFLOT **flight, int * maxRecord, int countRecords );

void printRecord( AEROFLOT *flight, int num );

void printList( AEROFLOT *flight, int countRecords );

void deleteRecord( AEROFLOT* flight, int *countRecords );

void addRecord( AEROFLOT** flight, int *maxRecord, int *countRecords );

void inFile( AEROFLOT* flight, int countRecords );

int fromFile( AEROFLOT** flight, int *maxRecord, int *countRecords );

int getWordsArray( char *st, char *arrayWords[] );

void findRecords( AEROFLOT* flight, int countRecords );

int compare( AEROFLOT flight, char *plane );

int compare( const void * left, const void * right );

void sort( AEROFLOT* flight, int countRecords );

void mysort( AEROFLOT *flight, int countRecords );

void swap( AEROFLOT *flight, int j );


int main(){

	const int maxRecord = 2;
	int countRecords = 0;
	AEROFLOT *flight = new AEROFLOT[maxRecord];
	menu( flight, maxRecord, countRecords );
	return 0;
}

int menuTitle(){
  	int c;
	std::cout << "1. Input of new records"<< std::endl;

	std::cout << "2. viewing of the list"<< std::endl;

	std::cout << "3. Remove record from the list"<< std::endl;

	std::cout << "4. Add record in the list"<< std::endl;

	std::cout << "5. Save in the file"<< std::endl;

	std::cout << "6. load from the file"<< std::endl;

	std::cout << "7. Search record"<< std::endl;
	
	std::cout << "8. Quick sort"<< std::endl;

	std::cout << "9. Sort"<< std::endl;

	std::cout << "0. Exit"<< std::endl;

  do {
    std::cout << ( "Enter number: ");
    std::cin >> c;
  } while(c < 0 || c > 9);
  return c;
}

void menu( AEROFLOT *flight, int maxRecord, int countRecords ){

    while( 1 ) {

	    int choice = menuTitle();

	    switch( choice ) {

		case 1: 
			countRecords = enter( &flight, &maxRecord, countRecords );
			break;

		case 2: 
			printList( flight, countRecords );     
			break;

		case 3:
			deleteRecord( flight, &countRecords );
	        break;

		case 4: 
			addRecord( &flight, &maxRecord, &countRecords ); 
			break;

		case 5: 
			inFile( flight, countRecords );
			break;

		case 6: 
			fromFile( &flight, &maxRecord, &countRecords ); 
			break;

		case 7: 
			findRecords( flight, countRecords );  
			break;

		case 8: 
			sort( flight, countRecords );
			break;
		case 9:
			mysort( flight, countRecords );
			break;

		case 0:
			delete[]flight;
			return;
			break;
	    }
	std::cout << std::endl;
  }
  return;
}


AEROFLOT createRecord(){

	  AEROFLOT flight;

	  std::cout << "Enter destination: "; 
	  std::cin>>flight.destination;

	  std::cout << "Enter flight number: "; 
	  std::cin >> flight.flightNumber;


	  std::cout << "Enter plane type: ";
	  std::cin >> flight.planeType;

	  return flight;
}

void increaseSizeList( AEROFLOT** flight, int * maxRecord, int countRecords ){
	// создать новый массив в два раза больше исходного, скопировать все существующие записи из исходного в новый, освободить память первого исходного массива, и сохранить адрес нового массива
	AEROFLOT *newArray = new AEROFLOT[ ( *maxRecord ) * 2 ];

	for ( int i = 0; i < countRecords; i++ ){
		newArray[i] = ( *flight )[i];
	}

	*maxRecord *= 2;
	delete *flight;
	*flight = newArray;
}

int enter( AEROFLOT **flight, int * maxRecord, int countRecords ){
	int n;
	std::cout<<" enter the number of new records: ";
	std::cin>> n;
	n += countRecords;
	// если необходимо увеличить размер динамического массива с помощью функции increaseSizeList, ввести в массив с клавиатуры нужное количество записей (использовать ф-цию createRecord), вернуть новое количество записей
	
	while ( n > *maxRecord ){
		increaseSizeList( flight, maxRecord, countRecords );
	}

	for ( int i = countRecords; i < n; i++ ){
		( *flight )[i] = createRecord();
	}
	return n;	
}

void printRecord( AEROFLOT *flight, int num ){
	
	std::cout << flight[num].destination << " | " 
			  << flight[num].flightNumber << " | " 
			  << flight[num].planeType;
}

void printList( AEROFLOT *flight, int countRecords ){
	// красивый вывод содержимого массива 
	std::cout << std::endl << "destination | flight number | plane type" << std::endl;
	for ( int i = 0; i < countRecords; i++ ){
		printRecord( flight, i );
		std::cout << std::endl;
	}
}

void deleteRecord( AEROFLOT* flight, int *countRecords ){
	// удалить существующую запись со сдвигом
	std::cout << "Enter number of the deleted record: ";
	int num;
	std::cin >> num;

	for ( int i = num; i < *countRecords - 1; i++ ){
		flight[i] = flight[i+1];
	}
	( *countRecords )--;
}

void addRecord( AEROFLOT** flight, int *maxRecord, int *countRecords ){
	// добавить в конец массива новую запись, если необходимо размер массива увеличить
	if ( ( *countRecords ) + 3 > ( *maxRecord ) ){
		increaseSizeList( flight, maxRecord, *countRecords );
	}

	( *flight )[*countRecords] = createRecord();
	( *countRecords )++;
}

void inFile( AEROFLOT* flight, int countRecords ){
	std::ofstream out;
	out.open("AEROFLOT1.txt", std::ios::out);
	// запись в файл
	for ( int num = 0; num < countRecords; num++ ){
		out << flight[num].destination << " " 
			<< flight[num].flightNumber << " " 
			<< flight[num].planeType << "\n";
	}
	out.close(); 
}

int fromFile( AEROFLOT** flight, int *maxRecord, int *countRecords ){
	// чтение из файла
	std::ifstream in ("AEROFLOT2.txt", std::ifstream::in);
    in.seekg (-1,in.end);
    long size = in.tellg();
    size = size + 2;
    in.seekg (0, in.beg);

    char *array = new char[size];
    in.read( array, size );
	char **arrayWords = new char*[size];

   	for ( int j = 0; j < size; j++ ){
   		arrayWords[j] = new char[30];
   	}
	int rows = getWordsArray( array, arrayWords );

	if ( rows / 3 > *maxRecord ){
		increaseSizeList( flight, maxRecord, *countRecords );
	}

	for ( int arrayWordsIndex = 0, objectIndex = 0; arrayWordsIndex < rows; arrayWordsIndex += 3 ){

		int index = 0;
		int temp = 0;

		while ( arrayWords[ arrayWordsIndex ][ index ] ){
			( *flight )[ objectIndex ].destination[ index ] = arrayWords[ arrayWordsIndex ][ index ];
			index++;
		}
		index = 0;

		while ( arrayWords[ arrayWordsIndex + 1 ][ index ] ){
			temp = temp*10 + arrayWords[ arrayWordsIndex + 1 ][ index ] - 48;
			index++;
		}
		( *flight )[ objectIndex ].flightNumber = temp;
		index = 0;

		while ( arrayWords[ arrayWordsIndex + 2 ][index] ){
			( *flight )[ objectIndex ].planeType[ index ] = arrayWords[ arrayWordsIndex + 2 ][ index ];
			index++;		
		}
		objectIndex++;
	}


	*countRecords += rows / 3;
	in.close();
	return 0;
}

int getWordsArray( char *st, char *arrayWords[] ){
        int i = 0, j = 0;

        while( st[i] ) {
                int k = 0;

                while( st[i] == ' ' || st[i] == '\n' )
                        i++;

                while( st[i] != ' ' && st[i] != '\n' && st[i] ) {
                        arrayWords[j][k] = st[i];
                        k++;
                        i++;
                }
                arrayWords[j][k] = '\0';
                j++;
        }
        return j;
}

void findRecords( AEROFLOT* flight, int countRecords ){
	char plane[20];
	std::cout << "Enter plane type: "; 
	std::cin>> plane;
	// найти запись и вывести (использовать ф-цию compare)
	for ( int i = 0; i < countRecords; i++ ){

		if ( compare( flight[i], plane ) ){
			printRecord( flight, i );
			std::cout << std::endl;
		}
	}
}

int compare( AEROFLOT flight, char *plane ){ 			// для поиска
	
	if ( strcmp( flight.planeType, plane ) == 0 )
		return 1;
	return 0;
}


int compare1( const void * left, const void * right ){ 	//для qsort
	
	if ( strcmp( ( ( AEROFLOT* )left )->destination, ( ( AEROFLOT* )right )->destination ) > 0 )
		return 1;
	return 0;
}

int compare2( const void * left, const void * right ){ 	//для qsort
	
	if ( ( ( AEROFLOT* )left )->flightNumber > ( ( AEROFLOT* )right )->flightNumber )
		return 1;
	return 0;
}

int compare3( const void * left, const void * right ){ 	//для qsort
	
	if ( strcmp( ( ( AEROFLOT* )left )->planeType, ( ( AEROFLOT* )right )->planeType ) > 0 )
		return 1;
	return 0;
}

void sort ( AEROFLOT* flight, int countRecords ){
	//выполнить сортировку с помощью функции qsort

	char sort[30];
	std::cout << "Enter a sort field:(flightNumber/planeType/destination) ";
	std::cin >> sort;

	if ( strcmp( sort, "destination" ) == 0 ){
		qsort( flight, countRecords, sizeof( AEROFLOT ), compare1 );

	} else if( strcmp( sort, "flightNumber" ) == 0 ){
		qsort( flight, countRecords, sizeof( AEROFLOT ), compare2 );

	} else if( strcmp( sort, "planeType" ) == 0 ){
		qsort( flight, countRecords, sizeof( AEROFLOT ), compare3 );

	} else{
		std::cout << "Invalid value";
	}
}

void swap( AEROFLOT *flight, int j ){

	AEROFLOT *temp = new AEROFLOT();

	strcpy( temp->destination, flight[j].destination );
	temp->flightNumber = flight[j].flightNumber;
	strcpy( temp->planeType, flight[j].planeType );

	strcpy( flight[j].destination, flight[j + 1].destination );
	flight[j].flightNumber = flight[j + 1].flightNumber;
	strcpy( flight[j].planeType, flight[j + 1].planeType );

	strcpy( flight[j + 1].destination, temp->destination );
	flight[j + 1].flightNumber = temp->flightNumber;
	strcpy( flight[j + 1].planeType, temp->planeType );

	delete temp;
}

void mysort ( AEROFLOT *flight, int countRecords){	
	//bubbleSort
	char sort[30];
	std::cout << "Enter a sort field:(flightNumber/planeType/destination) ";
	std::cin >> sort;
	char temp[30];
	
	if ( strcmp( sort, "destination" ) == 0 ){

		for ( int i = 0; i < countRecords - 1; i++ ){

			for ( int j = 0; j < countRecords - 1; j++ ){

				if ( strcmp( flight[j].destination, flight[j+1].destination ) > 0 ){
					swap( flight, j );
				} 
			}
		}
		return;

	} else if( strcmp(sort, "flightNumber" ) == 0){

		for ( int i = 0; i < countRecords - 1; i++ ){

			for ( int j = 0; j < countRecords - 1; j++ ){
				if ( flight[j].flightNumber > flight[j+1].flightNumber ){
					swap( flight, j );
				}
			}
		}
		return;

	} else if( strcmp(sort, "planeType") == 0 ){

		for ( int i = 0; i < countRecords - 1; i++ ){

			for ( int j = 0; j < countRecords - 1; j++ ){
				if ( strcmp( flight[j].planeType, flight[j+1].planeType ) > 0 ){
					swap( flight, j );
				} 
			}
		}
		return;
	} else{
		std::cout << "invalid value" << std::endl;
		return;
	}
	return;
}