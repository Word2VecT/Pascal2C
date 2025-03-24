#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    char dna[MAX_LENGTH];
    int gc_count = 0;
    int total_length = 0;
    scanf("%s", dna);
    
    // 计算序列长度和GC含量
    for (int i = 0; dna[i] != '\0'; i++) {
        char base = toupper(dna[i]);
        if (base == 'G' || base == 'C') {
            gc_count++;
        }
        total_length++;
    }
    
    // 计算GC含量比例（小数形式）
    double gc_content = (double)gc_count / total_length;
    
    printf("%.3f\n", gc_content);
    
    return 0;
}