#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void  envi(char **env);
void val(char *token,char *capital,char *pays1,char *pays2,char *pays3,char *pays4,char *env);
void tok(char *token,char *env);

void genere(char *capital,char *pays1,char *pays2,char *pays3,char *pays4,int pv,int *score);
	
int main() {
	
	int a=0;
    int pv=6;
    int score=0;
    char *env=NULL;
    char capital[256];
    char pays1[255];
    char pays2[256];
    char pays3[256];
    char pays4[256];
    char buffer[255];
    envi(&env);
    strncpy(buffer,env,255);
	val(buffer,capital,pays1,pays2,pays3,pays4,env);
	printf("%s",pays1);
	genere(capital,pays1,pays2,pays3,pays4,pv,&score);
    
	
    
	
	
	
    return 0;
}
void envi(char** env){
		*env=getenv("QUERY_STRING");
}
void tok(char *token,char *env){
	token=strtok(env,"&");
}
void val(char *token,char *capital,char *pays1,char *pays2,char *pays3,char *pays4,char *env){
	token=strtok(env,"&");
	sscanf(token,"capital=%s",capital);
	token=strtok(NULL,"&");
	sscanf(token,"pays1=%s",pays1);
	token=strtok(NULL,"&");
	sscanf(token,"pays2=%s",pays2);
	token=strtok(NULL,"&");
	sscanf(token,"pays3=%s",pays3);
	token=strtok(NULL,"&");
	sscanf(token,"pays4=%s",pays4);
}

void genere(char *capital,char *pays1,char *pays2,char *pays3,char *pays4,int pv,int *score){
	
	printf("Content-type: text/html\n\n");
	printf("<!DOCTYPE html>");
	printf("<html><head><title></title><style>");
	printf(".conteneur{display:flex;flex-wrap:wrap;justify-content:space-around;align-item:center;background-color:blue;}");
	printf("img{width: 500px;height:500px;margin-left:-20px;}");
	printf(".REPONSE{");
	printf("display:flex;");
	printf("background-color:yellow;");
	printf("flex-wrap:wrap;");
	printf("width:45%%;");
	printf("justify-content:space-around;}");
	printf(".choix{");
	printf("background-color:pink;");
	printf("width:55%%;");
	printf("display:flex;");
	printf("flex-direction:column;}");
	printf(".entrer{display:block;width: 50%%;height: 200px;text-align: center;font-size: 40px;margin-left: 132px;margin-top: 206px;}");
	printf(".reponse{width:200px;color:white;margin:20px;height:300px;font-size:25px;text-align:center;}");
	printf("button{width:250px;height:200px;}");
	printf("button:hover{background-color:purple;color:white;}");
	printf("nav{display:flex;height:100px;font-size:20px;justify-content:space-around;}");
	printf(".conteneur2{background-color:green;display:flex;}");
	
	printf("</style></head><body>");
	printf("<nav><li>pv=%d</li><li>score=%d</li></nav>", pv, *score);
	printf("<div class=\"conteneur\">");
	printf("<img src=\"%s\"/>",capital);
	printf("</div>");
	printf("<div class=\"conteneur2\">");
	printf("<div class=\"REPONSE\">");
	printf("<div class=\"reponse\"><button>%s</button></div>",pays1);
	printf("<div class=\"reponse\"><button>%s</button></div>",pays2);
	printf("<div class=\"reponse\"><button>%s</button></div>",pays3);
	printf("<div class=\"reponse\"><button>%s</button></div>",pays4);
	printf("</div>");
	printf("<div class=\"choix\">");
	printf("<form action=\"https://localhost/tosaf261.cgi\" method=\"get\">");
	printf("<input class=\"entrer\"type=\"text\" name=\"reponse\"></input>");
	printf("<input class=\"entrer\"type=\"submit\" value=\"envoyer\"></input>");
	printf("</form></div></div></body></html>");
	
	
	
}	
	
	
	
	

