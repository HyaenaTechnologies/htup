#ifndef SYSTEM_UPDATE_H
#define SYSTEM_UPDATE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// APT Upgrade
int aptUpgrade(void);

// Distribution Release Upgrade
int distributionUpgrade(void);

// DNF Upgrade
int dnfUpgrade(void);

// DNF System Upgrade
int dnfSystemUpgrade(void);

// YUM Upgrade
int yumUpgrade(void);

#endif 