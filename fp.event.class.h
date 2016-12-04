#ifndef fp_event_class_H_
#define fp_event_class_H_
using namespace std;

class event_c{
	friend class Database;

      protected:
      string ename;
      double price;
	  unsigned int capacity;
      
      public:
      ~event_c();
      event_c();
      event_c(string e);
	  event_c(string e, double cost);
	  event_c(string e, double cost,unsigned int max);
      void virtual displayInfo();
};

event_c::event_c(){
};

event_c::event_c(string e){
	//constructor to make an event with NO cost and NO capacity
	ename=e;
	price=0;
	capacity=1000000000;
}
event_c::event_c(string e,double cost){
	//constructor to make an event with a cost and NO capacity
	ename=e;
	price=cost;
	capacity=1000000000;
}

event_c::event_c(string e, double cost, unsigned int max){
	//constructor to make an event with a cost and a capacity limit
      ename=e;
      price=cost;
	  capacity=max;
};

event_c::~event_c(){
};

void event_c::displayInfo(){
      cout<<ename<<": $"<<price<<"  Available Tickets: "<<capacity;
};

#endif
