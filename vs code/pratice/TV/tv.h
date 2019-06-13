/*
请编写电视机类，电视机有开机和关机状态，有音量，有频道，
提供音量操作的方法，频道操作的方法。由于电视机只能逐一调整频道，
不能指定频道，增加遥控类，遥控类除了拥有电视机已有的功能，再增加根据输入调台功能。
*/
#ifndef __TV_H_
#define __TV_H_

class Remote;

class Televition{
    friend class Remote;
public:
    enum{On, Off};
    enum{minVol, maxVol=100};
    enum{minChannel=1, maxChannel=255};

    Televition();   //无参构造
    void OnOrOff(); //打开电视机
    void VolumeUp();//调高音量
    void VolumeDown();//调低音量
    void ChannelUp();//更换电视频道
    void ChannelDown();
    void ShowTvleState();

private:
    int state;
    int volume;
    int channel;
};

class Remote{
public:
    Remote(Televition *televition);
public:
    void OnOrOff();
    void VolumeUp();
    void VolumeDown();
    void ChannelUp();
    void ChannelDown();
    void SetChannel(int channel);   //设置频道，新增功能
    void ShowTvleState();
private:
    Televition *ptelevition;
};

#endif