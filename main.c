#include<stdio.h>
#include<string.h>
#include<stdbool.h>   

/*let input names of players who are playing*/
char p1[1000]; char p2[1000];
/*first i am creating empty tic tac toe board of size 3 * 3*/
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int r,c; /*there are index variable used to work with our space matrix*/
/*r = row, c = column */
char token='X'; /*this variable will help us to take input */
bool tie = false;
void boardprint(){

    

    
    /*let us create game board using printf() function*/
    printf("    |    |    \n");
    printf(" %c  | %c  | %c\n",space[0][0],space[0][1],space[0][2]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c\n",space[1][0],space[1][1],space[1][2]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c\n",space[2][0],space[2][1],space[2][2]);
    
}
void check(){
    
    int digit; /*player will enter the number and we will mark 0 or X at that place*/
    if(token=='X'){
        printf("%s Please Enter ",p1);
        scanf("%d",&digit);
    }
    if(token=='0'){
        printf("%s Please Enter ",p2);
        scanf("%d",&digit);
    }
    
    
    if(digit==1){ /*if player enter digit 1 we will modify (0,0) index*/ 
        r = 0; c = 0;
    }
    if(digit==2){ /*if player enter digit 2 we will modify (0,1) index*/ 
        r = 0; c = 1;
    }
    if(digit==3){ /*if player enter digit 3 we will modify (0,2) index*/ 
        r = 0; c = 2;
    }
    if(digit==4){ /*if player enter digit 4 we will modify (1,0) index*/ 
        r = 1; c = 0;
    }
    if(digit==5){ /*if player enter digit 5 we will modify (1,1) index*/ 
        r = 1; c = 1;
    }
    if(digit==6){ /*if player enter digit 6 we will modify (1,2) index*/ 
        r = 1; c = 2;
    } 
    if(digit==7){ /*if player enter digit 7 we will modify (2,0) index*/ 
        r = 2; c = 0;
    }
    if(digit==8){ /*if player enter digit 8 we will modify (2,1) index*/ 
        r = 2; c = 1;
    }
    if(digit==9){ /*if player enter digit 9 we will modify (2,2) index*/ 
        r = 2; c = 2;
    } 
    else if(digit<1 || digit>9){
        printf("Invalid Digit ");
    }
    
    
    if(token=='X' && space[r][c]!='X' && space[r][c]!='0'){
        space[r][c] = 'X'; /*if player one enter X we will mark its position (r,c) as X but for 
                                  next player token is needed to be modify as 0*/
        token = '0';            
    }
    else if(token=='0' && space[r][c]!='X' && space[r][c]!='0'){
        space[r][c] = '0'; /*if player two enter 0 we will mark its position (r,c) as 0 but for 
                                  next player token is needed to be modify as X*/
        token = 'X';            
    }  
    else{
        printf("There is no empty space ");
        check(); /*calling function again and again to mark all indexes*/
        
    }

}

bool result(){ /*lets check who wins the game*/
    for(int i = 0;i<3;i++){ /*this loop will do this task of win or loose*/
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
        
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    {
    return true;
    }
              
    for(int i=0;i<3;i++){
        /*check whether game still working or not*/
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='0'){
                return false;            }
        }
    }
    tie = true;
    return false;
}
int main(){
 
    printf("Enter the name of First Player : ");
    scanf("%s",&p1);
    printf("Enter the name of Second Player : ");
    scanf("%s",&p2);
    
    
    while(!result()){
        boardprint();
        check();
        result();
    }
    if(token=='X' && tie==false){
        printf("%s Wins ",p2);
        
    }
    else if(token=='0' && tie==false){
        printf("%s Wins ",p1);
    }
}