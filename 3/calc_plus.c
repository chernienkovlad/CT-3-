#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char** argv)
{
    const struct option long_option[] =
    {
        {"add", no_argument, NULL, 'a'},
        {"subtract", no_argument, NULL, 's'},
        {"multiply", no_argument, NULL, 'm'},
        {"divide", no_argument, NULL, 'd'},
        {NULL, no_argument, NULL, 0}
    };

    int a_flag = 0, s_flag = 0, m_flag = 0, d_flag = 0;
    int opt = 0;
    char short_option[] = "asmd";

    while ((opt = getopt_long(argc, argv, short_option, long_option, NULL)) != -1)
    {
        switch (opt)
        {
            case 'a': a_flag++; break;
            case 's': s_flag++; break;
            case 'm': m_flag++; break;
            case 'd': d_flag++; break;
        }
    }

    int a = atoi(argv[optind]), b = atoi(argv[optind+1]);

    if (m_flag) { a *= b; }
    if (d_flag) { a /= b; }
    if (a_flag) { a += b; }
    if (s_flag) { a -= b; }

    printf("%d\n", a);

    return 0;
}
