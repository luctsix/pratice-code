#include "tv.cpp"

void test01(){
    Televition *tv = new Televition;
    tv->ShowTvleState();
    tv->OnOrOff();
    for(int i=0; i<=30; i++)
    {
         tv->VolumeUp();
         for(int j=0; j<3; j++)
         {
             tv->ChannelUp();
         }
    }
    tv->ShowTvleState();
}
void test02(){
    Televition *tv = new Televition;
    Remote     *rm = new Remote(tv);

    rm->ShowTvleState();
    int i = 0;
    while(i++ != 30)
    {
        rm->VolumeUp();
        rm->ChannelUp();
        rm->ChannelUp();
    }
    while(i-- != 24)
    {
        rm->ChannelDown();
    }

    rm->ShowTvleState();
    rm->SetChannel(199);
    rm->ShowTvleState();
}

int main(){
    //test01();
    test02();
    return 0;
}