#define METRIC_MODE 0
#define US_MODE 1
void get_info(int mode, double *distance, double *fuel_consumed);
void show_info(int mode, double distance, double fuel_consumed);
void set_mode(int *mode);
void eat_newline(void);