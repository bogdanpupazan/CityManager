#include <iostream>
#include <string>
#include <vector>


class Person
{
public:
    std::string mName;
    unsigned short int mAge;
    double mSalary;
    Person()
    {
        mAge=0;
        mSalary=0;
        mName="";
    }
    Person(std::string a, unsigned int b, double c)
    {
        mName=a;
        mAge=b;
        mSalary=c;
    }

    bool operator==(const Person& person1) const
    {
        if(mName==person1.mName&&mAge==person1.mAge&&mSalary==person1.mSalary)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(const Person& person1)const
    {
        if(mName<person1.mName)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Building
{
protected:
    std::string mBuildingName;
    std::string mType;
    Person mCoordinator;
    std::vector<Person> mEmployees;
    std::vector<Person> mCitizens;
public:
    Building(std::string a, std::string b)
    {
        mBuildingName=a;
        mType=b;
    }
    virtual void add(const Person& person1)=0;
    virtual void remove(const Person& person1)=0;
    virtual Building* operator+(const Person& person1)=0;
    virtual Building* operator-()
    {
        return nullptr;
    }
    virtual Building* operator-(const Person& person1){
        return nullptr;
    }
    std::string getBuildingName() const{
        return mBuildingName;
    }
    std::string getType() const{
        return mType;
    }
    unsigned short int getEmployeesSize()const{
        return mEmployees.size();
    }
    unsigned short int getCitizensSize()const{
        return mCitizens.size();
    }
    Person getEmployee(unsigned short int a)const{
        return mEmployees.at(a);
    }
    Person getCitizen(unsigned short int a)const{
        return mCitizens.at(a);
    }
    Person getCoordinator()const{
        return mCoordinator;
    }
};

class CityHall:public Building
{
public:
    CityHall(std::string a):Building(a, "CityHall")
    {
        mCitizens.clear();
        mCoordinator=Person();
    }
    Building* operator+(const Person& person1)
    {
        if(mCoordinator.mName=="")
        {
            mCoordinator=person1;
        }
        return this;
    }
    Building* operator-()
    {
        mCoordinator=Person();
        return this;
    }
    void add(const Person& person1)
    {
        mCitizens.push_back(person1);
    }
    void remove(const Person& person1)
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName==person1.mName)
            {
                mCitizens.erase(mCitizens.begin()+i);
            }
        }
    }
};

class Hospital:public Building
{
public:
    Hospital(std::string a):Building(a, "Hospital")
    {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+(const Person& person1)
    {
        mEmployees.push_back(person1);
        return this;
    }
    Building* operator-(const Person& person1)
    {
        for(int i=0;i<mEmployees.size();i++)
        {
            if(mEmployees[i].mName==person1.mName)
            {
                mEmployees.erase(mEmployees.begin()+i);
            }
        }
        return this;
    }
    void add(const Person& person1)
    {
        mCitizens.push_back(person1);
    }
    void remove(const Person& person1)
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName==person1.mName)
            {
                mCitizens.erase(mCitizens.begin()+i);
            }
        }
    }
};

class PoliceStation:public Building
{
public:
    PoliceStation(std::string a):Building(a,"PoliceStation")
    {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building* operator+(const Person& person1)
    {
        mEmployees.push_back(person1);
        return this;
    }
    Building* operator-(const Person& person1)
    {
        for(int i=0; i<mEmployees.size();i++)
        {
            if(mEmployees[i].mName==person1.mName)
            {
                mEmployees.erase(mEmployees.begin()+i);
            }
        }
        return this;
    }
    void add(const Person& person1)
    {
        mCitizens.push_back(person1);
    }
    void remove(const Person& person1)
    {
        for(int i=0; i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName==person1.mName)
            {
                mCitizens.erase(mCitizens.begin()+i);
            }
        }
    }
};

class House:public Building
{
private:
    unsigned short int mMaxNumber;
public:
    House(std::string a, unsigned b):Building(a,"House")
    {
        mCitizens.clear();
        mCoordinator=Person();
        mMaxNumber=b;
    }
    Building* operator+(const Person& person1)
    {
        if(mCoordinator.mName.empty()==1)
        {
            mCoordinator=person1;
        }
        return this;
    }
    Building* operator-()
    {
        mCoordinator=Person();
        return this;
    }
    void add(const Person& person1)
    {
        if(mCitizens.size()<mMaxNumber-1)
        {
            mCitizens.push_back(person1);
        }
    }
    void remove(const Person& persoana)
    {
            for(int i=0; i<mCitizens.size();i++)
            {
                if(mCitizens[i].mName==persoana.mName)
                {
                    if(mCitizens[i].mAge>=18)
                    {
                        mCitizens.erase(mCitizens.begin()+i);
                    }
                }
            }
    }
};

class Block:public Building
{
private:
    unsigned short int mMaxNumberPerFloor;
    int numar_etaje;
public:
    Block(std::string a, unsigned int b, unsigned int c):Building(a, "Block")
    {
        numar_etaje=b*c;
        mMaxNumberPerFloor=c;
        mCitizens.clear();
        for(int i=0; i<b*c;i++)
        {
            mCitizens.push_back(Person());
        }
    }
    Building* operator+(const Person& person1)
    {
        if(mCoordinator.mName.empty()==1)
        {
            mCoordinator=person1;
        }
        return this;
    }
    Building* operator-()
    {
        mCoordinator=Person();
        return this;
    }
    void add(const Person& person1)
    {
        for(int i=0;i<numar_etaje;i++)
        {
            if(mCitizens[i].mName.empty()==1)
            {
                mCitizens[i]=person1;
                break;
            }
        }
    }
    void remove(const Person& person1)
    {
        for(int i=0; i<numar_etaje; i++)
        {
            if(mCitizens[i].mName==person1.mName)
            {
                if(mCitizens[i].mAge>=18)
                {
                    mCitizens[i]=Person();
                }
            }
        }
    }
};
int nCH,nHp,nPS,nH,nBs,nC,nB,nPc;
int k;
double nM,nD,nP,nCHE;
double naP,aP;
double sD,sM,sCHE,sP;

int main()
{
    std::string actiune,A;
    std::vector<Building*> bld;
    std::vector<std::string> ctz;
    while(std::cin>>actiune)
    {
        if(actiune=="add")
        {
            std::string arg;
            std::cin>>arg;
            if(arg=="CityHall")
                {
                    std::string s;
                    std::cin>>s;
                    bld.push_back(new CityHall(s));
                }
            if(arg=="PoliceStation")
                {
                    std::string s;
                    std::cin>>s;
                    bld.push_back(new PoliceStation(s));
                }
            if(arg=="Hospital")
                {
                    std::string s;
                    std::cin>>s;
                    bld.push_back(new Hospital(s));
                }
            if(arg=="Block")
                {
                    std::string s;
                    std::cin>>s;
                    unsigned int et,maxi;
                    std::cin>>et>>maxi;
                    bld.push_back(new Block(s,et,maxi));
                }
            if(arg=="House")
                {
                    std::string s;
                    std::cin>>s;
                    unsigned int maxi;
                    std::cin>>maxi;
                    bld.push_back(new House(s,maxi));
                }
            if(arg=="coordinator")
                {
                    std::string s;
                    std::cin>>s;
                    unsigned int v;
                    double sal;
                    std::cin>>v>>sal;
                    std::string l;
                    std::cin>>l;
                    for(int i=0;i<bld.size();i++)
                    {
                        if(bld[i]->getBuildingName()==l)
                        {
                            bld[i]->operator+(Person(s,v,sal));
                        }
                    }
                }
            if(arg=="citizen")
                {
                    std::string s;
                    std::cin>>s;
                    unsigned int v;
                    double sal;
                    std::cin>>v>>sal;
                    std::string l;
                    std::cin>>l;
                    for(int i=0;i<bld.size();i++)
                    {
                        if(bld[i]->getBuildingName()==l)
                        {
                            bld[i]->add(Person(s,v,sal));
                        }
                    }
                }
            if(arg=="employee")
                {
                    std::string s;
                    std::cin>>s;
                    unsigned int v;
                    double sal;
                    std::cin>>v>>sal;
                    std::string l;
                    std::cin>>l;
                    for(int i=0;i<bld.size();i++)
                    {
                        if(bld[i]->getBuildingName()==l)
                        {
                            bld[i]->operator+(Person(s,v,sal));
                        }
                    }
                }
        }
        if(actiune=="remove")
        {
            std::string arg;
            std::cin>>arg;
                if(arg=="coordinator")
                    {
                        std::string s,l;
                        std::cin>>s>>l;
                        for(int i=0;i<bld.size();i++)
                        {
                            if(bld[i]->getBuildingName()==l)
                            {
                                bld[i]->operator-();
                            }
                        }
                    }
                if(arg=="citizen")
                    {
                        std::string s,l;
                        std::cin>>s>>l;
                        for(int i=0;i<bld.size();i++)
                        {
                            if(bld[i]->getBuildingName()==l)
                            {
                                bld[i]->remove(Person(s,0,0));
                            }
                        }
                    }
                if(arg=="employee")
                    {
                        std::string s,l;
                        std::cin>>s>>l;
                        for(int i=0;i<bld.size();i++)
                        {
                            if(bld[i]->getBuildingName()==l)
                            {
                                bld[i]->operator-(Person(s,0,0));
                            }
                        }
                    }
        }
    }
    for(int i=0;i<bld.size();i++)
        {
            if(bld[i]->getType()=="CityHall")
                {
                    nCH++;
                    if (bld[i]->getCoordinator().mName.empty()==0)
                    {
                        nM++;
                        sM=sM+bld[i]->getCoordinator().mSalary;
                    }
                    for(int j=0; j<bld[i]->getCitizensSize();j++)
                        {
                            nCHE++;
                            sCHE=sCHE+bld[i]->getCitizen(j).mSalary;
                        }
                }
            if(bld[i]->getType()=="Hospital")
                {
                    nHp++;
                    nPc=nPc+bld[i]->getCitizensSize();
                    for(int j=0; j<bld[i]->getEmployeesSize();j++)
                        {
                            nD++;
                            sD=sD+bld[i]->getEmployee(j).mSalary;
                        }
                }
            if(bld[i]->getType()=="PoliceStation")
                {
                    nPS++;
                    for(int j=0; j<bld[i]->getEmployeesSize();j++)
                        {
                            nP++;
                            sP=sP+bld[i]->getEmployee(j).mSalary;
                        }
                    for(int j=0; j<bld[i]->getCitizensSize();j++)
                        {
                            naP++;
                            aP=aP+bld[i]->getCitizen(j).mAge;
                        }
                }
             if(bld[i]->getType()=="Block")
                nBs++;
             if(bld[i]->getType()=="House")
                nH++;
        }
        if(nCH>=3&&nPS>=3&&nHp>=2&&nBs>=4&&nH>=8)
        {
            std::cout<<"Type: Capital";
        }
        else if(nCH>=2&&nPS>=2&&nHp>=1&&nBs>=1&&nH>=4)
        {
            std::cout<<"Type: Town";
        }
        else
        {
            std::cout<<"Type: Village";
        }
        std::cout<<'\n';
        std::cout<<"Number of patients in hospitals: "<<nPc<<'\n';
        if(sD==0)
            {
                std::cout<<"Average salary for doctors: 0\n";
            }
        else
            {
                std::cout<<"Average salary for doctors: "<<sD/nD<<'\n';
            }
        if(sP==0)
            {
                std::cout<<"Average salary for cops: 0\n";
            }
        else
            {
                std::cout<<"Average salary for cops: "<<sP/nP<<'\n';
            }
        if(sM==0)
            {
                std::cout<<"Average salary for mayors: 0\n";
            }
        else
            {
                std::cout<<"Average salary for mayors: "<<sM/nM<<'\n';
            }
        if(sCHE==0)
            {
                std::cout<<"Average salary for city hall employees: 0\n";
            }
        else
            {
                std::cout<<"Average salary for city hall employees: "<<sCHE/nCHE<<'\n';
            }
        if(naP==0)
            {
                std::cout<<"Average age of busted in police stations: 0\n";
            }
        else
            {
                std::cout<<"Average age of busted in police stations: "<<aP/naP<<'\n';
            }
        for(int i=0;i<bld.size();i++)
        {
            nC=nB=0;
            if(bld[i]->getType()=="House")
            {
                if(bld[i]->getCoordinator().mName.empty()==0)
                nC++;
                nC=nC+bld.at(i)->getCitizensSize();

                std::cout<<"Number of people in House"<<" "<<bld[i]->getBuildingName()<<": "<<nC;
                std::cout<<'\n';
            }
            if(bld[i]->getType()=="Block")
            {
                if(bld[i]->getCoordinator().mName.empty()==0)
                {
                    nB++;
                }
                for(int j=0;j<bld[i]->getCitizensSize();j++)
                {
                    if(bld[i]->getCitizen(j).mName.empty()==0)
                    {
                        nB++;
                    }
                }
                std::cout<<"Number of people in Block"<<" "<<bld[i]->getBuildingName()<<": "<<nB<<'\n';
            }
        }
        std::cout<<"Administrators of house and block:"<<" ";
        for(int i=0;i<bld.size();i++)
            {
                if(bld[i]->getType()=="House"&&bld[i]->getCoordinator().mName.empty()==0)
                {
                    A=bld[i]->getCoordinator().mName;
                    for(int j=false;j<bld.size();j++)
                    {
                        if(bld[j]->getType()=="Block"&&bld[j]->getCoordinator().mName==A)
                        {
                            ctz.push_back(A);
                            k=1;
                        }
                    }
                }
            }
        if(k==0)
        {
            std::cout<<"Nobody";
        }
        else
        {
            for(int i=0; i<ctz.size();i++)
            {
                std::cout<<ctz[i]<<" ";
            }
        }
    return 0;
}
