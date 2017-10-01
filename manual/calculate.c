#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // orig
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%*s %*s %lf %lf\n", &orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

    // opt
    double opt_sum_a[argc-1], opt_sum_f[argc-1];
    for (i = 1; i < argc; ++i) {
        fp = fopen(argv[i], "r");
        if (!fp) {
            fp = fopen("orig.txt", "r");
            if (!fp) {
                printf("ERROR opening input file opt.txt\n");
                exit(0);
            }
        }
        double opt_a, opt_f;
        opt_sum_a[i-1] = opt_sum_f[i-1] = 0.0;
        for (int j = 0; j < 100; j++) {
            if (feof(fp)) {
                printf("ERROR: You need 100 datum instead of %d\n", j);
                exit(0);
            }
            fscanf(fp, "%*s %*s %lf %lf\n", &opt_a, &opt_f);
            opt_sum_a[i-1] += opt_a;
            opt_sum_f[i-1] += opt_f;
        }
        fclose(fp);
    }

    fprintf(output, "append() %lf ",orig_sum_a / 100.0);
    for (i = 0; i < argc - 1; ++i) {
        fprintf(output, "%lf", opt_sum_a[i] / 100.0);
        i != argc - 2 ? fprintf(output, " ") : fprintf(output, "\n");
    }
    fprintf(output, "findName() %lf ", orig_sum_f / 100.0);
    for (i = 0; i < argc - 1; ++i) {
        fprintf(output, "%lf", opt_sum_f[i] / 100.0);
        i != argc - 2 ? fprintf(output, " ") : fprintf(output, "");
    }
    fclose(output);

    return 0;
}
