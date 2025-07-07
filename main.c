#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOV 2
#define OPERATION 4

void afisare_clasica(char line[]) {
	char *p, *val;
	int spaces = 0, n = 0, i = 0;
	n = strlen(line);
	// afisare_clasica(line);
	spaces = 0;
	for (i = 0; i < n; i++) {
		if (line[i] == ' ')
			spaces++;
	}
	if (strchr(line, '&')) {
		p = strtok(line, " \t;");
		printf("AND e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strchr(line, '|')) {
		p = strtok(line, " \t;");
		printf("OR e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strchr(line, '^')) {
		p = strtok(line, " \t;");
		printf("XOR e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strchr(line, '+')) {
		p = strtok(line, " \t;");
		printf("ADD e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strchr(line, '-')) {
		p = strtok(line, " \t;");
		printf("SUB e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strchr(line, '*')) {
		p = strtok(line, " \t;");
		char var = p[0];
		if (var != 'a')
			printf("MOV eax, e%sx\n", p);
		val = p;
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("MUL e%sx\n", p);
		else
			printf("MUL %s\n", p);
		if (var != 'a')
			printf("MOV e%sx, eax\n", val);
	} else if (strchr(line, '/')) {
		p = strtok(line, " \t;");
		val = p;
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] == '0') {
			printf("Error\n");
			return;
		}
		if (val[0] != 'a')
			printf("MOV eax, e%sx\n", val);
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("DIV e%sx\n", p);
		else
			printf("DIV %s\n", p);
		if (val[0] != 'a')
			printf("MOV e%sx, eax\n", val);
	} else if (strstr(line, "<<")) {
		p = strtok(line, " \t;");
		printf("SHL e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " '\t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else if (strstr(line, ">>")) {
		p = strtok(line, " \t;");
		printf("SHR e%sx, ", p);
		for (int i = 0; i < OPERATION; i++)
			p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	} else {
		// implementez MOV
		p = strtok(line, " \t;");
		printf("MOV e%sx, ", p);
		p = strtok(NULL, " \t;");
		p = strtok(NULL, " \t;");
		if (p[0] >= 'a' && p[0] <= 'z')
			printf("e%sx\n", p);
		else
			printf("%s\n", p);
	}
}

int main(void) {
	char line[255], *p, *val, *op, var, *limit;
	while (fgets(line, 255, stdin)) {
		line[strlen(line) - 1] = '\0';
		if (line[0] == '\0')
			continue;
		if (strstr(line, "if")) {
			p = strtok(line, " \t;()");
			p = strtok(NULL, " \t();");
			op = strtok(NULL, " \t;()");
			val = strtok(NULL, " \t;()");
			printf("CMP e%sx, %s\n", p, val);
			if (strstr(op, "<="))
				printf("JG end_label\n");
			else if (strstr(op, "<"))
				printf("JGE end_label\n");
			else if (strstr(op, "=="))
				printf("JNE end_label\n");
			else if (strstr(op, ">="))
				printf("JL end_label\n");
			else if (strstr(op, ">"))
				printf("JLE end_label\n");
			else
				printf("JE end_label\n");
			fgets(line, 255, stdin);
			line[strlen(line) - 1] = '\0';
			while (line[0] != '}') {
				afisare_clasica(line);
				fgets(line, 255, stdin);
				line[strlen(line) - 1] = '\0';
			}
			printf("end_label:\n");
		} else if (strstr(line, "while")) {
			printf("start_loop:\n");
			p = strtok(line, " \t;()");
			p = strtok(NULL, " \t();");
			op = strtok(NULL, " \t;()");
			val = strtok(NULL, " \t;()");
			printf("CMP e%sx, %s\n", p, val);
			if (strstr(op, "<="))
				printf("JG end_label\n");
			else if (strstr(op, "<"))
				printf("JGE end_label\n");
			else if (strstr(op, "=="))
				printf("JNE end_label\n");
			else if (strstr(op, ">="))
				printf("JL end_label\n");
			else if (strstr(op, ">"))
				printf("JLE end_label\n");
			else
				printf("JE end_label\n");
			fgets(line, 255, stdin);
			line[strlen(line) - 1] = '\0';
			while (line[0] != '}') {
				afisare_clasica(line);
				fgets(line, 255, stdin);
				line[strlen(line) - 1] = '\0';
			}
			printf("JMP start_loop\n");
			printf("end_label:\n");

		} else if (strstr(line, "for")) {
			p = strtok(line, " \t();");
			p = strtok(NULL, " \t();");
			var = p[0];
			p = strtok(NULL, " \t();");
			p = strtok(NULL, " \t();");
			val = p;
			p = strtok(NULL, " \t();");
			p = strtok(NULL, " \t();");
			op = p;
			p = strtok(NULL, " \t();");
			limit = p;
			printf("MOV e%cx, %s\n", var, val);
			printf("start_loop:\n");
			printf("CMP e%cx, %s\n", var, limit);
			if (strstr(op, "<="))
				printf("JG end_label\n");
			else
				printf("JGE end_label\n");
			fgets(line, 255, stdin);
			line[strlen(line) - 1] = '\0';
			while (line[0] != '}') {
				afisare_clasica(line);
				fgets(line, 255, stdin);
				line[strlen(line) - 1] = '\0';
			}
			printf("ADD e%cx, 1\n", var);
			printf("JMP start_loop\n");
			printf("end_loop:\n");
		} else
			afisare_clasica(line);
	}
	return 0;
}
