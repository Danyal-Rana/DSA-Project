#include <iostream>
using namespace std;
class convert{
	public:convert(){
	}
	
int stringconversion(string s){
	if(s.compare("Shifa_hospital")==0){
		return 0;
	}else if(s.compare("Paf_hospital")==0){
        return 1;
    }else if(s.compare("Madina_market")==0){
        return 2;
    }else if(s.compare("Raj_shadi_hall")==0){
        return 3;
    }else if(s.compare("Ali_mobile_plaza")==0){
        return 4;
    }else if(s.compare("ssg-qrf")==0){
        return 5;
    }else if(s.compare("pindi_cricket_staium")==0){
        return 6;
    }else if(s.compare("Comsats_university_islamabad")==0){
        return 7;
    }else if(s.compare("Hostel_city")==0){
        return 8;
    } else if(s.compare("Fire_brigade_station")==0){
        return 9;
    
    } else if(s.compare("Islamabad_police_station")==0){
        return 10;
    } else if (s.compare("Medical_centre")==0){
        return 11;
    }else if(s.compare("sadqabad_police_station")==0){
        return 12;
    }else if(s.compare("Ayub_nation_park")==0){

        return 13;
    }else if(s.compare("ali_pur")==0){
        return 14;
    }else if(s.compare("rawal_hospital")==0){
        return 15;
    } else if(s.compare("Bani_gala")==0){
        return 16;
    }else if(s.compare("Blue_area")==0){
        return 17;
    } else if(s.compare("Jamia_msjid")==0){
        return 18;
    } else if(s.compare("pindi_firebrigade_station")==0){
        return 19;
    }
    else if(s.compare("quaid_e_azam_hospital")==0){
        return 20;
    }
    return 999;
}
string intconversion(int a){
	if(a==0){
		return "Shifa hospital";
	}else if(a==1){
		return "Paf hospital";
	}
	else if(a==2){
		return "Madina market";
	}
	else if(a==3){
		return "Raj shadi hall";
	}
	else if(a==4){
		return "Ali mobile plaza";
	}
	else if(a==5){
		return "ssg-qrf";
	}
	else if(a==6){
		return "pindi cricket staium";
	}
	else if(a==7){
		return "Comsats university islamabad";
	}
	else if(a==8){
		return "Hostel city";
	}
	else if(a==9){
		return "Fire_brigade_station";
	}
	else if(a==10){
		return "Islamabad police station";
	}
	else if(a==11){
		return "Medical centre";
	}
	else if(a==12){
		return "sadqabad police station";
	}
	else if(a==13){
		return "Ayub nation park";
	}
	else if(a==14){
		return "ali pur";
	}
	else if(a==15){
		return "rawal hospital";
	}
	else if(a==16){
		return "Bani gala";
	}
	else if(a==17){
		return "Blue area";
	}
	else if(a==18){
		return "Jamia msjid";
	}
	else if(a==19){
		return "pindi_firebrigade_station";
	}
	else if(a==20){
		return "quaid e azam hospital";
	}
	return "";
}

};
