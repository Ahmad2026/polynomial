#include<iostream>
using namespace std;

class Terms
{
    public:
    int coeff;
    int exp;
};

class Poly
{
    private:
    int n;
    Terms *t;
    public:
    Poly(int n)
    {
        this->n = n;
        t = new Terms[n];
    }
    ~Poly(){
        delete [] t;
    }
    Poly operator+(Poly &p);
    friend istream & operator>>(istream &is,Poly &p);
    friend ostream & operator<<(ostream &os,Poly &p);
};

istream & operator>>(istream &is,Poly &p){
    cout<<"ENTER ALL TERMS"<<endl;
    for(int i=0;i<p.n;i++){
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    return is;
}
ostream & operator<<(ostream &os,Poly &p){
    for(int i=0;i<p.n;i++){
        cout<<p.t[i].coeff<<"x^"<<p.t[i].exp;
        if(i<p.n-1){
            cout<<"+";
        }
    }
    cout<<endl;
    return os;
}
Poly Poly::operator+(Poly &p){
    Poly *sum = new Poly(n+p.n);
    int i,j,k;
    i=j=k=0;
    while(i<n&&j<p.n)
    {
     if(t[i].exp>p.t[j].exp)
     {
         sum->t[k++] = t[i++];
     }   
     else if(t[i].exp<p.t[j].exp)
     {
         sum->t[k++] = p.t[j++];
     }   
     else
     {
         sum->t[k] = t[i];
         sum->t[k++].coeff = t[i++].coeff+p.t[j++].coeff;
     }
     
    }
    for(;i<n;i++)
    {
        sum->t[k++] = t[i];
    }
     for(;j<n;j++)
     {
        sum->t[k++] = p.t[j];
    }
    sum->n = k;
    return *sum;
}

int main()
{
    Poly p1(4),p2(4);
    cin>>p1;
    cin>>p2;
    cout<<" FIRST EXPRESSION IS::"<<endl;
    cout<<p1;
    cout<<" SECOND EXPRESSION IS::"<<endl;
    cout<<p2;
    Poly sum = p1+p2;
    cout<<" FINAL EXPRESSION IS::"<<endl;
    cout<<sum;
    return 0;
}