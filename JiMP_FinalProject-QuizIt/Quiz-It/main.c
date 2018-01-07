//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char questionText[256];
    char answers[4][64];
    int correctAnswer;
}Questions;

Questions* loadQuestions(int*);
void addQuestion(void);
void printQuestion(int,Questions*,int*,int);
void printLogo(void);
void mainLoop(void);

int main(int argc,char* argv[]){
    srand(time(NULL));

    if(argc>1){
        if(strcmp(argv[1],"--add")==0) addQuestion();
        else printf("Wrong command-line argument!");
    }
    else{
        while(1){
            mainLoop();
        }
    }
    return 0;
}

void mainLoop(void){
    int prizes[13]={0,500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000};

    printLogo();
    printf("Press p to play new game or other character to exit: ");
    char c = getchar();
    if (c == 'p'){
        fflush(stdin);

        int counter = 0;
        int* pCounter = &counter;
        Questions* question = loadQuestions(pCounter);
        printf("\nDuring question type x to leave with all the money you have won\n\n");
        int usedQuestions[counter];
        int questionNumber = rand()%counter;

        for(int i = 0; i < 12;++i){
            while(usedQuestions[questionNumber]==1){
                questionNumber = rand()%counter;
            }
            usedQuestions[questionNumber]=1;
            printQuestion(questionNumber,question,prizes,i);

            int userAnswer =-1;
            while((userAnswer-'A'>3 || userAnswer-'A'<0) && userAnswer!='x'){
                userAnswer=getchar();
                fflush(stdin);
            }
            if (userAnswer-65==((question+questionNumber)->correctAnswer)){
                printf("\nCorrect!\n\n");
                if(i == 11){
                    printf("You won 1000000$!!!");
                }
            }
            else if(userAnswer==120){

                printf("Congratulation! You won %d$",prizes[i]);
                break;
            }
            else{
                printf("\nWrong! You lose!\n\n");
                if(i >1){
                    if(i>6){
                        printf("You have guaranteed 40000$");
                    }
                    else{
                        printf("You have guaranteed 1000$");
                    }
                }
                break;
            }
            fflush(stdin);
        }
    }
    else{
        exit(0);
    }
}

Questions* loadQuestions(int *n){
    FILE *file = fopen("questions.bin","rb");
    Questions q, *qs = NULL;
    *n = 0;
    if(file==NULL){
        printf("Error during opening a file!");
        exit(1);
    }
    while (fread(&q, sizeof(Questions),1,file)==1){
        qs = (Questions*) realloc(qs,((*n)+1)*sizeof(Questions));
        *(qs+(*n))=q;
        ++(*n);
    }
    fclose(file);

    return qs;
}

void addQuestion(void){
    Questions question;
    FILE* file = fopen("questions.bin","ab");
    char c;
    printf("Question: ");
    fflush(stdin);
    scanf("%[^\n]s",question.questionText);
    printf("Possible answers: ");
    fflush(stdin);

    for(int i = 0; i < 4; ++i){
        printf("-> %c: ",'A'+i);
        scanf("%[^\n]s",question.answers[i]);
        fflush(stdin);
    }

    printf("Correct answer: ");
    scanf("%c",&c);
    question.correctAnswer = c-'A';

    fwrite(&question,sizeof(Questions),1,file);
    fclose(file);
}

void printQuestion(int questionNumber,Questions* question,int* prizes,int level){
    printf("Question for %d$\n%s\n\n",prizes[level+1],(question+questionNumber)->questionText);
    for(int j = 0; j < 4;++j){
        printf("[%c]: %s\n",j+'A',(question+questionNumber)->answers[j]);
    }
    printf("\n");
}


void printLogo(void){
    printf(
"\n\n  sSSSs   d       b d sSSSSSs      d sssssssss\n"
" S     S  S       S S      s       S     S\n"
"S       S S       S S     s        S     S\n"
"S       S S       S S    s         S     S\n"
"S       S S       S S   s          S     S\n"
" S   s S   S     S  S  s           S     S\n"
"  sss sss    ssss   P sSSSSSs      P     P\n\n\n");
}
