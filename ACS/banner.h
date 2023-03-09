#define NULL_BYTE "\x00"
#define LINE1 "     _______________________________________________ \n"
#define LINE2 "    /    _____    ______________      __   _________/\n"
#define LINE3 "   /    /     |    |     _______|    /    /________\n"
#define LINE4 "  /    /______|    |    |           /_________    /\n"
#define LINE5 " /    ________     |    |_______    _________/   /\n"
#define LINE6 "/____/        |___||____________|  /____________/\n"
#define LINE7 "\t[Acrimacs Control Systems] (v1.0)\t\t\n"
#define BANNER LINE1 LINE2 LINE3 LINE4 LINE5 LINE6 LINE7 NULL_BYTE
#define CMD_PROMPT "[ACS]:> " NULL_BYTE

#define VERSION_INFO "ACS :Version(1.0)\n"
#define ARCH_INFO "CPU :esp8266\n"
#define PROCESSOR_NAME "Processor :ESP8266\n"
#define DEVELOPER_NAME "Developer: Acrimacs (acrimacs.com)\n"
#define SYSTEM_INFO VERSION_INFO ARCH_INFO PROCESSOR_NAME DEVELOPER_NAME NULL_BYTE

#define CMD_LINE0 "\n\t[Acrimacs Control Systems]\t\n"
#define CMD_LINE1 "help - Show this message\n"
#define CMD_LINE2 "gpio-ctl -m <gpio-mode> <gpio-pin> - Control GPIO Mode\n"
#define CMD_LINE3 "gpio-ctl -s <gpio-state> <gpio-pin> - Control GPIO State\n"
#define CMD_LINE4 "gpio-ctl -a  - Get GPIO state information\n"
#define CMD_LINE5 "reset - Soft reset system\n"
#define CMD_LINE6 "sysinfo - Get system information\n"
#define HELP_INFO CMD_LINE0 CMD_LINE1 CMD_LINE2 CMD_LINE3 CMD_LINE4 CMD_LINE5 CMD_LINE6 NULL_BYTE
