#include <stdio.h>

int main (){
    //this program will do nothing whatsoever
    //it probably won.t even compile, but that
    ///isn.t the point. this is purely to test
    //gcc -E preprocessing to see how comments
    //are removed. 
    
    some/* crazy */stuff
    some/* crazy */ stuff
    some/*crazy /*crazy*/*/stuff
    "some /* crazy */ stuff"
    some/* "crazy" */ stuff
    some /* crazy stuff */
    george is /* this should delete *****/awesome
    seriously, "i just /*this is inside quotes so it should not delete */ cant believe how awesome /*
    all of this should print, since it is still inside of a quote */george is"
    
    this will be a /* unclosed comment
          
          return 0;
          }

