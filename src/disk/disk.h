#ifndef DISK_H
#define DISK_H

typedef unsigned int VIKASHOS_DISK_TYPE;

// Represents a real physical hard disk.
#define VIKASHOS_DISK_TYPE_REAL 0

struct disk
{
    VIKASHOS_DISK_TYPE type;
    int sector_size;
};

int read_disk_sector(int lba, int total, void* buf);

#endif
