#include<bits/stdc++.h>
using namespace std;

/*
Situação: Temos uma área quadrada e temos que completar ela com strings, sendo que deve estar completamente cheia, área completa, nos é dado 3 strings, sendo só de A, B e C, 
e nos é dado a quantidade de strings e seu tamanho, x e y, sua coluna vai até x e a quantidade é y, altura, podemos rotacionar a string colocando na vertical ou horizontal. 
Com isso temos 2 casos, ou botamos todas uma em baixo da outra, ou irá ter uma na horizontal e o resto na vertical, para isso fixamos a maior coordenada em x dos pontos, 
e verificamos o primeiro caso que é todos os X's tem que serem iguais, e a soma das alturas, y, deve ser igual ao lado, pra formar o quadrado, senão temos o segundo caso:
que é pegamos o que tem maior X, coluna, e fixamos ele, e pegamos o restante da altura, ai fazemos a verificação que se algum x == rem, rotacionamos, swap, e verificamos o seguinte:
que é o que precisamos ambos os Y's precisam ter altura rem, e a soma deles precisam ser igual a coluna que fixamos, com isso basta imprimir, se nao -1.
*/

struct point{
    int x, y;
    char ch;
    
    void print(){
        for(int i = 0; i < this->y; i++){
            for(int j = 0; j < this->x; j++) cout<<this->ch;
            
            cout<<'\n';
        }
    }
};

int main(){
    point a, b, c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    a.ch = 'A'; b.ch = 'B'; c.ch = 'C';
    
    if(a.y > a.x) swap(a.x, a.y);
    if(b.y > b.x) swap(b.x, b.y);
    if(c.y > c.x) swap(c.x, c.y);
    
    if(a.x == b.x && a.x == c.x){
        if(a.y+b.y+c.y == c.x){
            cout<<b.x<<endl;
            a.print();
            b.print();
            c.print();
            return 0;
        }
        else{
            cout<<-1<<endl;
            return 0;
        }
    }
    
    if(c.x > a.x) swap(a, c);
    if(a.x > b.x) swap(a, b);
    
    int rem = b.x - b.y;
    
    if(a.x == rem) swap(a.x, a.y);
    if(c.x == rem) swap(c.x, c.y);
    
    if(a.y == rem && c.y == rem && a.x+c.x == b.x){
        cout<<b.x<<endl;
        b.print();
        
        for(int i = 0; i < rem; i++){
            for(int j = 0; j < a.x; j++) cout<<a.ch;
            for(int j = 0; j < c.x; j++) cout<<c.ch;
            
            cout<<endl;
        }
        return 0;
    }
    
    cout<<-1<<endl;
    
    return 0;
}   
