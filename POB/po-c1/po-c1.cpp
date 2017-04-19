#include <iostream>
#include <ctime>
class Stos
{
private:
  int dane[100];
  int n;
  int id;
public:
    Stos(int id){
        this->id = id;
        n=0;
        std::cout << "["<< id <<"] Pojawiam sie!" << std::endl;
    }
    ~Stos(){
        std::cout << "["<< id <<"] Znikam!" << std::endl;
    }

  void push(int e)   { dane[n++] = e; }
  int  pop()         { return dane[--n]; }
  int  empty()       { return n==0; }
  int size(){return n;}
  int getId() { return id;}
};
class Data{
    private:
    int day;
    int month;
    int year;
    public:
        Data(){
            time_t t = time(0);
                struct tm * now = localtime( & t );
                this->year = now->tm_year + 1900;
                this->month = now->tm_mon + 1;
                this->day = now->tm_mday;
        }
        Data(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void set(int d, int m, int r){
            this->day = d;
            this->month = m;
            this->year = r;
        }
        void print(){
            std::cout << day <<"-" << month << "-" << year;
        }

};
    void ex7(){
        std::cout <<"Startuje program" <<std::endl;
        for (int i = 0; i < 12; i++){
          Stos* stos = new Stos(i);
          std::cout << "Stworzylem stos!" << std::endl;
          stos->push(2); stos->push(5); stos->push(3);
          while(!stos->empty()){
            std::cout << stos->pop() << std::endl;
          }
            delete stos;
            std::cout << "Usunalem obiekt!" << std::endl;
        }
    }
    void ex10(){
        for (int i = 1; i <= 3; i++){
          Stos* stos = new Stos(i);
          delete stos;
        }
                std::cout <<std::endl;

        Stos* stacks[3];
        for (int i = 1; i <= 3; i++){
          stacks[i-1] = new Stos(i);
        }
        for (int i = 3; i >= 1; i--){
          delete stacks[(i-1)] ;
        }
        std::cout <<std::endl;
        for (int i = 1; i <= 3; i++){
          stacks[i-1] = new Stos(i);
        }
        for (int i = 1; i <= 3; i++){
          delete stacks[(i-1)] ;
        }
    }
    void dataEx2(){
        int day,month, year;
        std::cout <<"Podaj swoja date urodzenia! " << std::endl;
        std::cout <<"Podaj dzien! " << std::endl;
        std::cin >> day;
        std::cout <<"Podaj miesiac! " << std::endl;
        std::cin >> month;
        std::cout <<"Podaj rok! " << std::endl;
        std::cin >> year;
        Data* date = new Date(day, month, year);
        delete date;
    }
    main()
    {
    Data date;
    }
