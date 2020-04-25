struct Cls_{
		 Cls(char c, double d, int i){}
 
		char c;
		double d;
		int i;
};


char &get_c(Cls &cls) {
return ((Cls *)(&cls))->c;
}


double &get_d(Cls &cls) {
return ((Cls *)(&cls))->d;
}


int &get_i(Cls &cls) {
return ((Cls *)(&cls))->i;
}