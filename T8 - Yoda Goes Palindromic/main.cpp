//
//  main.cpp
//  T8 - Yoda Goes Palindromic
//
//  Created by Melissa Trevino on 3/16/16.
//  Copyright © 2016 Melissa Trevino. All rights reserved.
//
//  Melissa Treviño         A00816715
//  María Paula Anastás     A00817285

#include <iostream>
#include <string>
using namespace std;


bool VerPal (int p[],int i,int &TAMS)
{
    int iAux=0, iAux2=0;
    for(int iA=0; iA<i; iA++)
    {
        iAux+= p[iA];
        iAux2+= p[iA] % 2;
    }
    
    if(iAux2> 1)
    {
        cout<<0<<endl;
        return false;
    }
    
    TAMS= iAux;
    if(iAux2==0)
    {
        TAMS++;
    }
    
    return true;
}



double Factorial(double f[],int x)
{
    //la casilla 0 de la lista guarda el factorial más grande que se tiene guardado
    if(f[0]<x)
    {
        double Aux=f[int (f[0])];
        for(int i=int (f[0]);i<x+1;i++)
        {
            Aux*=i;
            f[i]=Aux;
        }
        f[0]=x;// nuevo factorial mayor
    }
    
    return f[x];
    
}

void CargaValores( string s, int ArrValores[],int &i)
{
    for(int c=0;c<s.length();c++)
    {
        s[c]=toupper(s[c]);
    }
    
    char a;
    int aux=0, n=0;
    
    while(s.length()!=0)
    {
        
        a=s[0];
        
        if(ispunct(a) || a==' ') //Mientras sea a
        {
            s.erase(0,1);
        }else{
            
            s.erase(0,1);
            aux++;
            
            while(s.find(a)!=std::string::npos)
            {
                
                if(s[n]==a)
                {
                    aux++;
                    cout<<s<<endl;
                    s.erase(n,1);
                    n--;
                    
                }
                n++;
                
            }
            //Mete los valores al arreglo
            ArrValores[i]=aux;
            // Pasa a casilla de valores siguiente
            i++;
            aux=0;
            n=0;
        }
        
    }
    
}

void Palindromo(int ArrValores[],int i,double fac[50])
{
    int TAMS=0;
    
    
    if(VerPal(ArrValores, i, TAMS)) //Verifica  si es palindrome
    {
        double A=Factorial(fac, (TAMS-1)/2);
        double B=1;
        for(int c=0;c<i-1;c++)
        {  if(ArrValores[c]%2==0)
        {
            B*=Factorial(fac, (ArrValores[c])/2);
        }else{
            if(ArrValores[c]!=1)
            {    B*=Factorial(fac, (ArrValores[c]-1)/2);
            }
        }
        }
        cout<<A/B<<endl;
        
    }
    
}

int main() {
    
    
    int ArrValores[50], iNum;
    string sFrase;
    double fact[50]{1,1};
    
    
    do{
        cout<< "Teclea la frase:"<<endl;
        getline(cin,sFrase);
        
        int i=0;
        
        CargaValores(sFrase,ArrValores,i);
        
        Palindromo(ArrValores, i, fact);
        i=0;
        
        cout<< "Otra frase?"<<endl;
        cout<< "1. Si"<<endl;
        cout<< "2. No"<<endl;
        
        cin>> iNum;
        cin.ignore();
    } while(iNum==1);
    
    return 0;
}


