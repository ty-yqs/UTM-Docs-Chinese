#include<iostream>
#include<stdio.h>
using namespace std;
char TrueCpu[40]={486,486-v1,Broadwell,Broadwell-IBRS,Broadwell-noTSX,Broadwell-noTSX-IBRS,Broadwell-v1 ,Broadwell-v2,Broadwell-v3,Broadwell-v4,Cascadelake-Server,Cascadelake-Server-noTSX ,Cascadelake-Server-v1,Cascadelake-Server-v2,Cascadelake-Server-v3,Cascadelake-Server-v4,Conroe,Conroe-v1,Cooperlake,Cooperlake-v1,Denverton,Denverton-v1,Denverton-v2,Dhyana,Dhyana-v1,EPYC,EPYC-IBPB,EPYC-Rome,EPYC-Rome-v1,EPYC-v1,EPYC-v2,EPYC-v3,Haswell,Haswell-IBRS,Haswell-noTSX,Haswell-noTSX-IBRS,Haswell-v1,Haswell-v2,Haswell-v3,Haswell-v4,Icelake-Client,Icelake-Client-noTSX,Icelake-Client-v1,Icelake-Client-v2,Icelake-Server,Icelake-Server-noTSX,Icelake-Server-v1,Icelake-Server-v2,Icelake-Server-v3,Icelake-Server-v4,IvyBridge,IvyBridge-IBRS,IvyBridge-v1,IvyBridge-v2,KnightsMill,KnightsMill-v1,Nehalem,Nehalem-IBRS,Nehalem-v1,Nehalem-v2,Opteron_G1,Opteron_G1-v1,Opteron_G2,Opteron_G2-v1,Opteron_G3,Opteron_G3-v1,Opteron_G4,Opteron_G4-v1,Opteron_G5,Opteron_G5-v1,Penryn,Penryn-v1,SandyBridge,SandyBridge-IBRS,SandyBridge-v1,SandyBridge-v2,Skylake-Client,Skylake-Client-IBRS,Skylake-Client-noTSX-IBRS,Skylake-Client-v1,Skylake-Client-v2,Skylake-Client-v3,Skylake-Server,Skylake-Server-IBRS,Skylake-Server-noTSX-IBRS,Skylake-Server-v1,Skylake-Server-v2,Skylake-Server-v3,Skylake-Server-v4,Snowridge,Snowridge-v1,Snowridge-v2,Westmere,Westmere-IBRS,Westmere-v1 ,Westmere-v2,athlon,athlon-v1,core2duo,core2duo-v1,coreduo,coreduo-v1,kvm32,kvm32-v1,kvm64,kvm64-v1,n270,n270-v1,pentium,pentium-v1,pentium2,pentium2-v1,pentium3,pentium3-v1,phenom,phenom-v1,qemu32,qemu32-v1,qemu64 ,qemu64-v1,base,host,max}
bool CheckCpu(char CPU)
{
    for(int j=0;j<=39){
        if CPU==TrueCpu[j]{
            return ture;
        }
    }
    return false;
}
int main()
{
    printf("｜------------------------｜\n");
    printf("｜-----QEMU命令生成工具-----｜\n");
    printf("｜------------------------｜\n");
    printf("｜-------作者：JR,Ty-------｜\n");
    printf("｜------------------------｜\n");
    printf("\n\n");
    printf("请选择您需要进行的操作:\n");
    printf("1 生成QEMU命令\n");
    printf("2 退出\n");
    int id;
    cin>>id;
    printf("\n");
    if (id==1){
        printf("请输入架构(如x86_64):");
        char a;
        cin>>a;
        printf("请输入加速器类型(如tcg):");
        char accel;
        cin>>accel;
        printf("请输入机型(如pc):");
        char b;
        cin>>b;
        printf("请输入设置运行内存(单位MB):");
        int mem=0;
        cin>>mem;
        bool wh=true;
        char c;
        //while(wh){
         //   printf("请输入CPU型号(如Skylake-Server-IBRS):");
        //    cin>>c;
         //   if(CheckCpu(c)){
        //        wh=false;
       //     }
       //     else{
        //        wh=true;
       //     }
       // }
        printf("请输入CPU型号(如Skylake-Serverver-IBRS):");
        cin>>c;
        printf("请输入设置核心数:");
        int cores=0;
        cin>>cores;
        printf("请设置声卡(如ac97):");
        char d;
        cin>>d;
        printf("请设置网卡(如e1000):");
        char e;
        cin>>e;
        printf("请设置显卡(如std):");
        char f;
        cin>>f;
        printf("需要挂载cd吗(1=需要 2=不需要):");
        int i=0;
        cin>>i;
        char g;
        if(i==1)
        {
            printf("请输入cd路径:");
            cin>>g;
        }
        printf("需要挂载硬盘吗(1=需要 2=不需要):");
        int hdd=0;
        cin>>hdd;
        char h;
        int p=0;
        if(hdd==1)
        {
            printf("需要那种方式连接硬盘(1=默认 2=virtio):");
            cin>>p;
            printf("请输入磁盘路径:");
            cin>>h;
        }
        printf("生成命令如下:");
        printf("qemu-system-");
        cout<<a;
        printf(" -accel ");
        cout<<accel;
        printf(" -machine ");
        cout<<b;
        printf(" -m ");
        cout<<mem;
        printf("M");
        printf(" -cpu ");
        cout<<c;
        printf(" -smp cores=");
        cout<<cores;
        printf(" -soundhw ");
        cout<<d;
        printf(" -net user -net nic,model=");
        cout<<e;
        printf(" -vga ");
        cout<<f;
        if(i==1)
        {
            printf(" -cdrom ");
            cout<<g;
        }
        if(hdd==1)
        {
            if(p==1)
            {
                printf(" -hda ");
                cout<<h;
            }
            if(p==2)
            {
                printf(" -drive file=");
                cout<<h;
                printf(",if=virtio,id=drive-virtio-disk0");
            }
        }
        printf("\n");
        return 0;
    }
    if(id==2){
        return 0;
    }
}