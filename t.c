#include <stdio.h>
#include <unistd.h>

#define MAXLINE 1024
static const char *optString = "lda:r:e:f:h?";
FILE *fp;


void
add_entry(char *entry, char *filename){
	int c;

	fp = fopen(filename, "a+");
	fprintf(fp, "%s\n", entry);
	fclose(fp);
}

void
list_entry(char *filename){
	char line[MAXLINE];
	
	if ((fp = fopen(filename, "r")) !=NULL)
		while (fgets(line, MAXLINE, fp) != NULL)
			printf("%s", line);
	fclose(fp);
}

void
display_help(){
	puts( "t - a simple tool to manage to-do list");
	puts( "Option:");
	puts( "  -h		show this help");
	puts( "  -a 'task'	and task to to-do list");
	puts( "  -l		list to-do list");
}

int
main(int argc, char **argv){
	char *task;
	int c;

	while ((c = getopt (argc, argv, optString)) != -1){
		if (c == 'a' ){
			task = optarg;
			add_entry(task,"todo");
		}
		else if (c == 'l')
			list_entry("todo");
		else if (c == 'h'|| c == '?')
			display_help();
	}
	

	return 0;
}
