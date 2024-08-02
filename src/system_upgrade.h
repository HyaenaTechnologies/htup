#ifndef SYSTEM_UPGRADE_H
#define SYSTEM_UPGRADE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// APT Upgrade
void aptUpgrade(void);

// Distribution Release Upgrade
void distributionUpgrade(void);

// DNF Upgrade
void dnfUpgrade(void);

// DNF System Upgrade
void dnfSystemUpgrade(void);

// YUM Upgrade
void yumUpgrade(void);

#endif
