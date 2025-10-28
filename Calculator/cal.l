%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%
[0-9]*["+"|"-"|"*"|"/"][0-9]* {return EXPR;}
. {return NOT;}
%%
int yywrap() { return 1; }

