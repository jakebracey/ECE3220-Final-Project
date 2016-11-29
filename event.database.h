class EventDatabase{
	friend class event_c;
	friend class admin_user_c;
	friend class user_c;
	
	private:
	vector<event_c> event_group;
	
	public:
	~EventDatabase();
	EventDatabase();
	void displayEvents();
};

EventDatabase::EventDatabase(){
	ifstream user_file("events.txt");
	
	string line;
	while(getline(user_file, line))
	{
		istringstream iss(line);
		string ename;
		double price;
		if((iss>>ename>>price)){
			event_c event_temp(ename, price);
			event_group.push_back(event_temp);
		}
	}
	
}


EventDatabase::~EventDatabase(){
	cout<<endl<<"Event Database Destroyed"<<endl;
}

void EventDatabase::displayEvents(){
	int i;
	cout<<endl<<endl<<"----  Available Events  ----";
	 for(i=0;event_group.size()>i;i++){
		 event_group[i].displayInfo();
	 }
	 cout<<endl<<endl;
}