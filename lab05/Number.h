class Number
{
   // add data members
   char *value;
   int base;
   
   int GetIntegerValue();
public:
   Number(const char * value, int base); // where base is between 2 and 16
   Number(int value, int base);
   Number(int number);
   ~Number();

   // add operators and copy/move constructor
   friend Number operator+(Number a, Number b);
   friend Number operator-(Number a, Number b);
   char operator[](int i);
   bool operator>(Number a);
   bool operator<(Number a);
   bool operator>=(Number a);
   bool operator<=(Number a);
   bool operator==(Number a);
   void operator--();
   void operator--(int);

   void operator=(int number);
   void operator=(const char *value);
   void operator+=(Number a);

   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};
