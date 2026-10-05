#include <stdio.h>
#include <string.h>
#include "system_tools.h"
#include "c_cpp_helper.h"
#include "kill.h"
#include "ipscan.h"

int main(void) {
    char user_input[256];

    while(1) {
        input_cmd(user_input, sizeof(user_input));
        
        if (strcmp(user_input, "wslinstubuntu") == 0) {
            wslinstubuntu();
        } else if (strcmp(user_input, "inst") == 0) {
            inst();
        } else if (strcmp(user_input, "rm") == 0) {
            rm();
        } else if (strcmp(user_input, "systeminfo") == 0) {
            systeminfo();
        } else if (strcmp(user_input, "c_cpp_helper") == 0) {
            c_cpp_helper();
        } else if (strcmp(user_input, "rep") == 0) {
            rep();
	} else if (strcmp(user_input, "kill") == 0) {
	    kill_proc_execvp();
	} else if (strcmp(user_input, "ipscan") == 0 || strcmp(user_input, "ip_scan") == 0) {
	    ipscan();
        } else if (strcmp(user_input, "exit") == 0) {
            break;
        } else {
            printf("not found ***\n");
        }
    }
    return 0;
}
