#include<iostream>
#include<string>

using namespace std;

class CPU{
    public:
        virtual void calculate() = 0;
        virtual void stop() = 0;
    
};
class MEM{
    public:
        virtual void storage() = 0;
        virtual void stop() = 0;
};
class GPU{
    public:
        virtual void display() = 0;
        virtual void stop() = 0;
};
class intelCPU:public CPU{
    public:
        void calculate(){
            cout<<"intel CPU starts working..."<<endl;
        }
        void stop(){
            cout<<"intel CPU stops working..."<<endl;
        }
};
class intelMEM: public MEM{
    public:
        void storage(){
            cout<<"intel MEM starts working..."<<endl;
        }
        void stop(){
            cout<<"intel MEM stops working..."<<endl;
        }
};
class intelGPU:public GPU{
    public:
        void display(){
            cout<<"intel GPU starts working..."<<endl;
        }
        void stop(){
            cout<<"intel GPU stops working..."<<endl;
        }
};
class DongzhiCPU:public CPU{
    public:
        void calculate(){
            cout<<"Dongzhi CPU starts working..."<<endl;
        }
        void stop(){
            cout<<"Dongzhi CPU stops working..."<<endl;
        }
};
class DongzhiMEM: public MEM{
    public:
        void storage(){
            cout<<"Dongzhi MEM starts working..."<<endl;
        }
        void stop(){
            cout<<"Dongzhi MEM stops working..."<<endl;
        }
};
class DongzhiGPU:public GPU{
    public:
        void display(){
            cout<<"Dongzhi GPU starts working..."<<endl;
        }
        void stop(){
            cout<<"Dongzhi GPU stops working..."<<endl;
        }
};

class computer{
    public:
        computer(CPU *c, MEM *m, GPU *g){
            cpu = c;
            mem = m;
            gpu = g;
        }
        
        virtual void show() = 0;
        virtual void working() = 0;
        virtual void shutdown() = 0;
    
        CPU *cpu;
        MEM *mem;
        GPU *gpu;
};

class IntelCom:public computer{
public:
    IntelCom(CPU *c, MEM *m, GPU *g):computer(c, m, g){}
    void show(){
        cout<<"this is a intel PC..."<<endl;
    }
    void working(){
        cpu->calculate();
        mem->storage();
        gpu->display();
    }
    void shutdown(){
        cpu->stop();
        mem->stop();
        gpu->stop();
    }
};
class DongzhiCom:public computer{
public:
    DongzhiCom(CPU *c, MEM *m, GPU *g):computer(c, m, g){}
    void show(){
        cout<<"this is a Dongzhi PC..."<<endl;
    }
    void working(){
        cpu->calculate();
        mem->storage();
        gpu->display();
    }
    void shutdown(){
        cpu->stop();
        mem->stop();
        gpu->stop();
    }
};


void Dothing(computer * com){
    com->show();
    com->working();
    com->shutdown();
}

int main(){
    CPU *c = new intelCPU;
    MEM *m = new intelMEM;
    GPU *g = new intelGPU;

    CPU *c2 = new DongzhiCPU;
    MEM *m2 = new DongzhiMEM;
    GPU *g2 = new DongzhiGPU;
    computer *com = new IntelCom(c2, m, g);
    Dothing(com);
    
    cout<<endl;
    computer *com2 = new DongzhiCom(c, m2, g2);
    Dothing(com2);

    delete c;
    delete m;
    delete g;
    delete com;
    delete c2;
    delete m2;
    delete g2;
    delete com2;

    return 0;
}