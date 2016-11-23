#ifndef fp_event_class_H_
#define fp_event_class_H_
using namespace std;

class event_c{
      friend class EventDatabase;

      protected:
      string ename;
      double price;
      
      public:
      ~event_c();
      event_c();
      event_c(string e, double cost);
      void virtual displayInfo();
};

event_c::event_c(){
};

event_c::event_c(string e, double cost){
      ename=e;
      price=cost;
};

event_c::~event_c(){
};

void event_c::displayInfo(){
      cout<<endl<<ename<<" "<<price;
};

#endif
