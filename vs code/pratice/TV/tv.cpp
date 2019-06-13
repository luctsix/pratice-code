#include<iostream>
#include "tv.h"

using namespace std;

Televition::Televition()  {
    this->state   = Off;
    this->channel = minChannel;
    this->volume  = minVol; 
}
void Televition::OnOrOff() {
    this->state = (this->state == On ? Off : On);
}
void Televition::VolumeUp(){
    if(this->volume >= maxVol)
        return;
    this->volume++;
}
void Televition::VolumeDown(){
    if(this->volume <= minVol)
        return;
    this->volume--;
}
void Televition::ChannelUp(){
    if(this->channel >= maxChannel)
        return;
    this->channel++;
}
void Televition::ChannelDown(){
    if(this->channel <= minChannel)
        return;
    this->channel--;
}
void Televition::ShowTvleState(){
    cout<<"----current state----"<<endl;
    cout<<"state: "<<(this->state == On ? "已开机" : "已关机")<<endl;
    cout<<"volume: "<<this->volume<<endl;
    cout<<"channel: "<<this->channel<<endl;
    cout<<"-----------------------"<<endl;
}
 /////////////////遥控器的接口//////////////////////
 Remote::Remote(Televition *televition){
     ptelevition = televition;
 }
void Remote::OnOrOff(){
    ptelevition->OnOrOff();
}
void Remote::VolumeUp(){
    ptelevition->VolumeUp();
}
void Remote::VolumeDown(){
    ptelevition->VolumeDown();
}
void Remote::ChannelUp(){
    ptelevition->ChannelUp();
}
void Remote::ChannelDown(){
    ptelevition->ChannelDown();
}
void Remote::SetChannel(int channel){       //设置频道，新增功能
    if(channel == ptelevition->channel)
        return;
    ptelevition->channel = channel;
}   
void Remote::ShowTvleState(){
    ptelevition->ShowTvleState();
}