#include<bits/stdc++.h>
using namespace std;

/*
                |-----------------|
                |       MP        | (Base class)
                |-----------------|
                        |
                        |
                        |
                |-----------------|
                |    Minister     | (Drived class)
                |-----------------|
                        |
                        |
                        |
                |-----------------|
                |       PM        | (Drived class)
                |-----------------|

*/                      

class MP  
{
    protected:
        string winning_constituency;
        string driver;
        long spending_limit;
    public:
        MP(const string& constituency){
            winning_constituency = constituency;
            driver = "Dummy";
            spending_limit = 100000;
    }

    string getConstituenty() const{
        return winning_constituency;
    }

    string getDriver() const{
        return driver;
    }

    bool exceedsSpendingLimit(long expenses) const{
        return expenses > spending_limit;
    }
};

class Minister : public MP{
    public:
        Minister(const string& constituency) : MP(constituency) {
            spending_limit = 1000000;
        }
};

class PM : public Minister{
    private:
        string aircraft_driver;
    
    public:
        PM(const string& constituency) : Minister(constituency){
            spending_limit = 10000000;
            aircraft_driver = "Demo";
        }

        /*
            getter method for driver name of Aircraft 
        */
        string getAircraftDriver() const{
            return aircraft_driver;
        }

        /*
            canArrest method gives permission to commissioner for action
        */
        bool canArrest(const Minister& minister) const {
            return true;
        }
};
/*
    Commissioner Class is Independent Body of Depict Indian Politics for action
*/
class Commissioner {
    public:
        /*
            canArrest Method perform the action of Commissioner
            @param : mp(const MP &)
            @return : void
        */
        void canArrest(const MP& mp) const {
            cout<<"Commissioner Arresting MP : "<<mp.getConstituenty()<<endl;
        }
        /*
            overloaded method(Polymorphism)
            canArrest Method perform the action of Commissioner on the bases of PM's Permission
            @param : minister(const Minister &), pm(const PM &)
            @return : void
        */  
        void canArrest(const Minister& minister, const PM& pm) const{
            if(pm.canArrest(minister)){
                cout<<"Commissioner Arresting Minister : "<<minister.getConstituenty()<<endl;
            }
            else{
                cout<<"Commissioner can not arrest Minister without PM's Permission"<<endl;
            }
        }
};
/*
    Test Case for Depict Indian Politics Program
*/
void test(){
    MP mp("Constituency 1");
    Minister minister("Constituency 2");
    PM pm("Constituency 3");

    Commissioner commissioner;
    commissioner.canArrest(mp);
    commissioner.canArrest(minister, pm);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
