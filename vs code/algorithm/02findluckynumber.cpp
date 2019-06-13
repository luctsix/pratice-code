#include <iostream>

using namespace std;

class Solution{
    public:
        bool findLuckyNun_1(int n, int m, int k){
            int a[n], b[m];
            cout<<"请输入数组a中的"<<n<<"个元素：";
            for(int i=0; i<n; i++)  cin>>a[i];
            cout<<"请输入数组b中的"<<m<<"个元素：";
            for(int i=0; i<m; i++)  cin>>b[i];
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(a[i]+b[j] == k)  return true;
                }
            }
            return false;
        }

        bool findLuckyNun(int n, int m, int k){
            int a[n], b[m];
            cout<<"请输入数组a中的"<<n<<"个元素：";
            for(int i=0; i<n; i++)  cin>>a[i];
            cout<<"请输入数组b中的"<<m<<"个元素：";
            for(int i=0; i<m; i++)  cin>>b[i];
            
            for(int i=0; ; )
            {
                if(a[i]+b[m] == k)
                {
                    //cout<<"yes"<<endl;
                    return true;
                }
                if(a[i]+b[m] < k)
                {
                    i++;
                }
                if(a[i]+b[m] > k)
                {
                    m--;
                }
                // 3   3    
                if(i==n || m==-1)
                {
                    return false;
                }
            }
        }
        
        int findLuckyBoy()
        {
            int n;
            
        }
};


int main()
{
    int n, m, k;
    cout<<"请输入n，m，k：";
    cin>>n>>m>>k;

    Solution a;
    
    if(a.findLuckyNun(n, m, k))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }


    return 0;
}