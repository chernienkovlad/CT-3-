#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	// getuid
	// getpwuid
	// getgid
	// getgrgid
	// getgrent
	// содержимое gr_mem

	struct passwd* pwuid = getpwuid(getuid());
	struct group* grgit =  getgrgid(getgid());
	
	printf("uid=%d(%s) gid=%d(%s) groups=", pwuid->pw_gid, pwuid->pw_name, grgit->gr_gid, grgit->gr_name);

	struct group* grent;
	while ((grent = getgrent()))
	{
		for (int i = 0; grent->gr_mem[i]; i++)
		{
			if (!strcmp(pwuid->pw_name, grent->gr_mem[i]))
			{
				printf("%d(%s) ", grent->gr_gid, grent->gr_name);
			}
		}
	}

	printf("\n");

	return 0;
}
