#include <iostream>
using namespace std;

int main()
{
    char tiep; 
    do { 

        long long i=0,so=0,ch,tong=0,tich=0;

        char dau_ct='+',dau_nc='+';

        bool co_so = false,co_bang=false,co_cach=false,co_dau=false,co_loi=false;

        cout<<"Nhap bieu thuc: ";

        while ((ch = getchar()) != '\n') {
            char c = char(ch);
            
            if(c>='0'&&c<='9')
            {
                if(co_so&&co_cach){
                    cout<<"Loi cu phap: thieu toan tu"<<endl;
                    co_loi=true; 
                    break;       
                }
                co_so=true;    
                co_cach=false;   
                i=c-'0';         
                so=so*10+i;      
            }

            else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='=')
            {
                co_cach=false;
                if(!co_dau&&!co_so){ 
                    cout<<"Loi cu phap: bieu thuc bat dau bang toan tu"<<endl;
                    co_loi=true;
                    break;
                }

                if(!co_so&&c!='='){
                    cout<<"Loi cu phap: hai toan tu lien nhau"<<endl;
                    co_loi=true;
                    break;
                }

                if(c=='='){
                    if(!co_so){
                        cout<<"Loi cu phap: thieu so truoc '='"<<endl;
                        co_loi=true;
                        break;
                    }
                    co_bang=true; 
                    break;        
                }   

                if(co_so){
                    if(dau_nc=='*') tich*=so;
                    else if(dau_nc=='/')
                    {
                        if(so==0)
                        {
                            cout<<"Loi: chia cho 0"<<endl;
                            co_loi=true;
                            break;
                        }
                        tich/=so;
                    }
                    else tich=so; 
                }

                if((c=='+'||c=='-'||c=='=')){
                    if(dau_ct=='+') tong+=tich;
                    else tong-=tich;
                    tich=0;
                    dau_nc='+';
                    if(c=='+'||c=='-') dau_ct=c; 
                }
                else {
                    dau_nc=c; 
                }

                so=0;
                co_so=false;
                co_dau=true;
            }

            else if(c==' ') co_cach=true;

            else{
                cout<<"Loi: ky tu khong hop le \'"<<c<<"\'"<<endl;
                co_loi=true;
                break;
            }
        }

        if (ch != '\n') {
            while ((ch = getchar()) != '\n');
        }


        if(!co_loi){
            if(!co_bang) cout<<"Loi: thieu dau '='"<<endl; 

            else cout<<"Ket qua: "<<tong<<endl;
        }

        while (true) {
            cout << "Tinh tiep (y/n)? ";
            cin>>tiep;
            while ((ch = getchar()) != '\n'); 
            if (tiep == 'y' || tiep == 'n' ) break;
        }
    } while (tiep == 'y'); 

    return 0;
}