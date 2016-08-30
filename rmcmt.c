#include <stdio.h>
#include <ctype.h>

#define inComment 0;
#define inCommentGotStar 1;
#define outComment 2;
#define outCommentGotSlash 3;
#define outCommentGotQuote 4;

int main(int argc, const char * argv[]) {
    
    int c;
    int state = 2;
    int examined;
    int currentline = 1;
    int openingline = 0;
    int commentclosed = 0;//set to 1 when comment opened(/*). set to 0 when comment closed(*/)
    
    while((c = getchar()) != EOF){
        
        examined = 0;
        
        if (c == '\n'){
            currentline++;
        }
        
        if (state == 1 && examined == 0){//begin inCommentGotStar
            
            if (c == '/'){
                state = outComment;
                examined++;
                commentclosed = 0;
            }
            
            
            if (c == '*'){
                state = inCommentGotStar;
                examined++;
            }
            
            
            if (c != '/' && c != '*'){
                state = inComment;
                examined++;
            }
            
        }//end inCommentGotStar
        
        
        if (state == 0 && examined == 0){//begin inComment
            
            if (c == '*'){
                state = inCommentGotStar;
                examined++;
            }
            
        }//end inComment
        
        
        if (state == 3 && examined == 0){//begin outCommentGotSlash
            
            if ( c == '*'){
                state = inComment;
                examined++;
                commentclosed = 1;
                openingline = currentline;
            }
            
            
            if ( c == '/'){
                printf("/");
                state = outCommentGotSlash;
                examined++;
            }
            
            
            if (c == '"'){
                state = outCommentGotQuote;
                examined++;
            }
            
            
            if ( c != '*' && c !='/' && c!= '"'){
                printf("/%c",c);
                state = outComment;
                examined++;
            }
            
        }//end outCommentGotSlash
        
        if (state == 2 && examined == 0){//begin outComment
            
            if (c == '/'){
                state = outCommentGotSlash;
                examined++;
            }
            
            
            if (c != '/'){
                printf("%c",c);
                examined++;
            }
            
            
            if (c == '"'){
                state = outCommentGotQuote;
                examined++;
            }
            
        }//end outComment
        
        if (state == 4 && examined == 0){//begin outCommentGotQuote
            
            if (c == '"'){
                printf("%c",c);
                state = outComment;
                examined++;
            }
            
            
            if (c != '"'){
                printf("%c",c);
                examined++;
            }
            
        }//end outCommentGotQuote
        
    }//end while
    
    if (commentclosed == 1){
        printf("\nerror at line %d. Comment /* was never closed.\n",openingline);
    }
        
    
    return 0;
    
}//end main
