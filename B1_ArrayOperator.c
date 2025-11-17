#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MaxSize 1000

typedef struct {
    int size;
    int row;
    int separator;
    int RandomMax;
    int RandomMin;
} SystemConfig;

void MainMenu();
void Config(SystemConfig *config);
void PrintArray(int a[], SystemConfig config);
void FillArray(int a[], SystemConfig config);
void FillRandom(int a[], SystemConfig config);
void FillKeyBoard(int a[], SystemConfig config);
void FillSameVal(int a[], SystemConfig config);
void FillArithSeq(int a[], SystemConfig config);
void Delete(int a[], SystemConfig *config);
int DeleteIndex(int a[], SystemConfig *config, int index);
int DeleteValue(int a[], SystemConfig *config, int value);
int DeleteRange(int a[], SystemConfig *config, int start, int end);
void Insert(int a[], SystemConfig *config);
int InsertIndex(int a[], SystemConfig *config, int index, int value);
int InsertOrder(int a[], SystemConfig *config, int value);
void Statistics(int a[], SystemConfig config);
int Max(int a[], SystemConfig config);
int Min(int a[], SystemConfig config);
double Average(int a[], SystemConfig config);
double Variance(int a[], SystemConfig config);
double StdDev(int a[], SystemConfig config);
void Search(int a[], SystemConfig config);
int SeqSearch(int a[], SystemConfig config, int value);
int BiSearch(int a[], SystemConfig config, int value);
void Judge(int a[], SystemConfig config);
int IsAsc(int a[], SystemConfig config);
int IsDesc(int a[], SystemConfig config);
int IsAllEqual(int a[], SystemConfig config);
void Arrange(int a[], SystemConfig config);
void Sort(int a[], SystemConfig config);
void BubbleSort(int a[], SystemConfig config);
void SelectSort(int a[], SystemConfig config);
void InsertSort(int a[], SystemConfig config);
void ExchangeSort(int a[], SystemConfig config);
void Reverse(int a[], SystemConfig config);
void RotateLeft(int a[], SystemConfig config, int k);
void RotateRight(int a[], SystemConfig config, int k);
void Application();
int JosephRing(int n, int k);
int *SievePrime(int n);

int main() {
    int a[MaxSize];
    SystemConfig config = {20, 10, 0, 100, 0};
    srand((unsigned)time(NULL));
    int choice = 1;
    
    while (choice) {
        MainMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 0: printf("退出成功\n"); return 0;
            case 1: Config(&config); break;
            case 2: PrintArray(a, config); break;
            case 3: FillArray(a, config); break;
            case 4: Delete(a, &config); break;
            case 5: Insert(a, &config); break;
            case 6: Statistics(a, config); break;
            case 7: Search(a, config); break;
            case 8: Judge(a, config); break;
            case 9: Arrange(a, config); break;
            case 10: Application(); break;
            default: printf("无效输入\n");
        }
    }

    return 0;
}

void MainMenu() {
    printf("\n数组运算器\n");
    printf("1 配置系统参数\n");
    printf("2 显示数组\n");
    printf("3 生成样本数据\n");
    printf("4 删除元素\n");
    printf("5 插入元素\n");
    printf("6 统计计算\n");
    printf("7 查找元素\n");
    printf("8 数组判断\n");
    printf("9 排列数组\n");
    printf("10 其他应用\n");
    printf("0 退出程序\n");
}

void Config(SystemConfig *config) {
    int choice = 1;
    while (choice) {
        printf("配置系统参数\n");
        printf("1 实际元素个数: %d\n", config->size);
        printf("2 每行显示元素个数: %d\n", config->row);
        printf("3 显示数据分隔符: %d\n", config->separator);
        printf("4 随机数最大值: %d\n", config->RandomMax);
        printf("5 随机数最小值: %d\n", config->RandomMin);
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf("请输入实际元素个数: "); scanf("%d", &config->size); break;
            case 2: printf("请输入每行显示元素个数: "); scanf("%d", &config->row); break;
            case 3: printf("请输入是否显示数据分隔符 (否:0, 是:1): "); scanf("%d", &config->separator); break;
            case 4: printf("请输入随机数最大值: "); scanf("%d", &config->RandomMax); break;
            case 5: printf("请输入随机数最小值: "); scanf("%d", &config->RandomMin); break;
            default: printf("无效输入\n");
        }
    }
}

void PrintArray(int a[], SystemConfig config) {
    printf("显示数组\n");
    if (!config.size) {
        printf("数组为空\n");
        return;
    }

    if (config.separator) {
        for (int i = 0; i < config.size; i++) {
            if (i % config.row == 0) {
                printf("\n");
            }
            if (i == config.size - 1) {
                printf("%d", a[i]);
            } else {
                printf("%d,", a[i]);
            }
        }
        printf("\n");
    } 
    else {
        for (int i = 0; i < config.size; i++) {
            if (i % config.row == 0) {
                printf("\n");
            }
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void FillArray(int a[], SystemConfig config) {
    int choice = 1;
    while (choice) {
        printf("生成样本数据\n");
        printf("1 用指定范围的随机数填充数组\n");
        printf("2 键盘输入\n");
        printf("3 整个数组填充同一个值\n");
        printf("4 用等差序列填充数组\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: FillRandom(a, config); break;
            case 2: FillKeyBoard(a, config); break;
            case 3: FillSameVal(a, config); break;
            case 4: FillArithSeq(a, config); break;
            default: printf("无效输入\n");
        }
    }
}

void FillRandom(int a[], SystemConfig config) {
    for (int i = 0; i < config.size; i++) {
        a[i] = rand() % (config.RandomMax - config.RandomMin + 1) + config.RandomMin;
    }
}

void FillKeyBoard(int a[], SystemConfig config) {
    printf("请输入 %d 个整数:\n", config.size);
    for (int i = 0; i < config.size; i++) {
        printf("请输入第%d个整数:", i+1);
        scanf("%d", &a[i]);
    }
}

void FillSameVal(int a[], SystemConfig config) {
    printf("请输入要填充的值: ");
    int c;
    scanf("%d", &c);
    for (int i = 0; i < config.size; i++) {
        a[i] = c;
    }
}

void FillArithSeq(int a[], SystemConfig config) {
    int start, delta;
    printf("请输入等差序列的起始值和公差:");
    scanf("%d%d", &start, &delta);
    for (int i = 0; i < config.size; i++) {
        a[i] = start + i * delta;
    }
}

void Delete(int a[], SystemConfig *config) {
    int choice = 1;
    int index, value, start, end;
    while (choice) {
        printf("删除\n");
        printf("1 删除指定下标的元素\n");
        printf("2 删除指定值的元素\n");
        printf("3 删除指定下标区间的一组元素\n");
        printf("0 返回上级\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf("请输入下标: ");
                    scanf("%d", &index); 
                    if (DeleteIndex(a, config, index) == -1) {
                        printf("删除失败：下标越界\n");
                    }
                    else {
                    printf("删除成功\n");
                    }
                    break;    
            case 2: printf("请输入值: "); 
                    scanf("%d", &value); 
                    DeleteValue(a, config, value); 
                    break;
            case 3: printf("请输入起始下标和结束下标: "); 
                    scanf("%d%d", &start, &end); 
                    DeleteRange(a, config, start, end); 
                    break;
            default: printf("无效输入\n");
        }
    }
}

int DeleteIndex(int a[], SystemConfig *config, int index) {
    if (index < 0 || index >= config->size) {
        return -1;
    }
    for (int i = index; i < config->size - 1; i++) {
        a[i] = a[i + 1];
    }
    config->size--;
    return config->size;
}

int DeleteValue(int a[], SystemConfig *config, int value) {
    for (int i = 0; i < config->size; i++) {
        if (a[i] == value) {
            config->size--;
            for (int j = i; j < config->size; j++) {
                a[j] = a[j + 1];
            }
            i--;
        }
    }
    return config->size;
}

int DeleteRange(int a[], SystemConfig *config, int start, int end) {
    if (start > end || start >= config->size || end < 0) {
        return -1;
    }
    int delta = end - start + 1;
    for (int i = end + 1; i < config->size; i++) {
        a[i - delta] = a[i];
    }
    config->size -= delta;
    return config->size;
}

void Insert(int a[], SystemConfig *config) {
    int choice = 1;
    int index, value;
    while (choice) {
        printf("插入\n");
        printf("1 按指定下标位置插入新元素\n");
        printf("2 在有序数组中插入新元素\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf("请输入下标和元素值: "); 
                    scanf("%d%d", &index, &value); 
                    if (InsertIndex(a, config, index, value) == -1) {
                        printf("插入失败：下标越界\n");
                    } 
                    else {
                        printf("插入成功\n");
                    }
                    break;
            case 2: printf("请输入插入值: "); 
                    scanf("%d", &value); 
                    InsertOrder(a, config, value); 
                    break;
            default: printf("无效输入\n");
        }
    }
}

int InsertIndex(int a[], SystemConfig *config, int index, int value) {
    if (index < 0 || index > config->size) {
        return -1;
    }
    for (int i = config->size; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = value;
    config->size++;
    return config->size;
}

int InsertOrder(int a[], SystemConfig *config, int value) {
    int i;
    if (IsAsc(a, *config)) {
        for (i = 0; i < config->size; i++) {
            if (value < a[i]) {
                break;
            }
        }
        for (int j = config->size; j > i; j--) {
            a[j] = a[j - 1];
        }
        a[i] = value;
        config->size++;
        return config->size;
    }

    if (IsDesc(a, *config)) {
        for (i = 0; i < config->size; i++) {
            if (value > a[i]) {
                break;
            }
        }
        for (int j = config->size; j > i; j--) {
            a[j] = a[j - 1];
        }
        a[i] = value;
        config->size++;
        return config->size;
    }
    return -1;
}

void Statistics(int a[], SystemConfig config) {
    int choice = 1;
    while (choice) {
        printf("统计\n");
        printf("1 求最大值\n");
        printf("2 求最小值\n");
        printf("3 求平均值\n");
        printf("4 求方差\n");
        printf("5 求均方差\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf("最大值: %d\n", Max(a, config)); break;
            case 2: printf("最小值: %d\n", Min(a, config)); break;
            case 3: printf("平均值: %.2f\n", Average(a, config)); break;
            case 4: printf("方差: %.2f\n", Variance(a, config)); break;
            case 5: printf("均方差: %.2f\n", StdDev(a, config)); break;
            default: printf("无效输入\n");
        }
    }
}

int Max(int a[], SystemConfig config) {
    int max = a[0];
    for (int i = 1; i < config.size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int Min(int a[], SystemConfig config) {
    int min = a[0];
    for (int i = 1; i < config.size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double Average(int a[], SystemConfig config) {
    double sum = 0;
    for (int i = 0; i < config.size; i++) {
        sum += a[i];
    }
    return sum / config.size;
}

double Variance(int a[], SystemConfig config) {
    double ave = Average(a, config);
    double sum = 0;
    for (int i = 0; i < config.size; i++) {
        sum += pow(a[i] - ave, 2);
    }
    return sum / config.size;
}

double StdDev(int a[], SystemConfig config) {
    return sqrt(Variance(a, config));
}

void Search(int a[], SystemConfig config) {
    int choice;
    int value;
    do {
        printf("查找\n");
        printf("1 普通查找\n");
        printf("2 二分查找\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf("请输入查找值: "); 
                    scanf("%d", &value); 
                    int result = SeqSearch(a, config, value); 
                    if (result == -1){
                        printf("查找值不存在");
                    }
                    else{
                        printf("找到下标:%d\n", result);
                    }
                    break;
            case 2: printf("请输入查找值: "); 
                    scanf("%d", &value); 
                    result = BiSearch(a, config, value);{
                        if (result == -2){
                            printf("非有序数组无法进行二分查找");
                        }
                        else if (result == -1){
                            printf("查找值不存在\n");
                        }
                        else {
                            printf("找到下标:%d\n", result);
                        }
                    }
                    break;
            default: printf("无效输入\n");
        }
    } while (choice);
}

int SeqSearch(int a[], SystemConfig config, int value) {
    for (int i = 0; i < config.size; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

int BiSearch(int a[], SystemConfig config, int value) {
    if (!(IsAsc(a, config) || IsDesc(a, config) || IsAllEqual(a, config))) {
        return -2;
    }

    if (IsAllEqual(a, config)) {
        if (a[0] == value) return 0;
        return -1;
    }

    int low = 0;
    int high = config.size - 1;
    int mid;

    if (IsAsc(a, config)) {
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == value) {
                return mid;
            } 
            else if (a[mid] < value) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    } 
    else if (IsDesc(a, config)) {
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == value) {
                return mid;
            } else if (a[mid] > value) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


void Judge(int a[], SystemConfig config) {
    int choice = 1;
    while (choice) {
        printf("判断\n");
        printf("1 是否升序排列\n");
        printf("2 是否降序排列\n");
        printf("3 是否全部相等\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: printf(IsAsc(a, config) ? "升序\n" : "非升序\n"); break;
            case 2: printf(IsDesc(a, config) ? "降序\n" : "非降序\n"); break;
            case 3: printf(IsAllEqual(a, config) ? "全部相等\n" : "不相等\n"); break;
            default: printf("无效输入\n");
        }
    }
}

int IsAsc(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int IsDesc(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int IsAllEqual(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        if (a[i] != a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void Arrange(int a[], SystemConfig config) {
    int choice = 1;
    while (choice) {
        printf("排列数组\n");
        printf("1 排序\n");
        printf("2 逆置数组\n");
        printf("3 左旋数组\n");
        printf("4 右旋数组\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: Sort(a, config); break;
            case 2: Reverse(a, config); break;
            case 3: {
                int k;
                printf("请输入左旋位数: ");
                scanf("%d", &k);
                RotateLeft(a, config, k);
                break;
            }
            case 4: {
                int k;
                printf("请输入右旋位数: ");
                scanf("%d", &k);
                RotateRight(a, config, k);
                break;
            }
            default: printf("无效输入\n");
        }
    }
}

void Sort(int a[], SystemConfig config) {
    int choice = 1;
    while (choice) {
        printf("排序方法\n");
        printf("1 冒泡排序\n");
        printf("2 选择排序\n");
        printf("3 插入排序\n");
        printf("4 交换排序\n");
        printf("0 返回上级菜单\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0: return;
            case 1: BubbleSort(a, config); break;
            case 2: SelectSort(a, config); break;
            case 3: InsertSort(a, config); break;
            case 4: ExchangeSort(a, config); break;
            default: printf("无效输入\n");
        }
    }
}

void BubbleSort(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        for (int j = 0; j < config.size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void SelectSort(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < config.size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void InsertSort(int a[], SystemConfig config) {
    for (int i = 1; i < config.size; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void ExchangeSort(int a[], SystemConfig config) {
    for (int i = 0; i < config.size - 1; i++) {
        for (int j = i + 1; j < config.size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Reverse(int a[], SystemConfig config) {
    int left = 0, right = config.size - 1;
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
}

void RotateLeft(int a[], SystemConfig config, int k) {
    k = k % config.size;
    for (int i = 0; i < k; i++) {
        int temp = a[0];
        for (int j = 1; j < config.size; j++) {
            a[j - 1] = a[j];
        }
        a[config.size - 1] = temp;
    }
}

void RotateRight(int a[], SystemConfig config, int k) {
    k = k % config.size;
    for (int i = 0; i < k; i++) {
        int temp = a[config.size - 1];
        for (int j = config.size - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
}

void Application() {
    int n, k;
    int choice = 1;
    int result;
    while (choice){
        printf("数组的其他应用\n");
        printf("1 约瑟夫环\n");
        printf("2 筛法求素数\n");
        printf("0 返回上级菜单\n");        
        scanf("%d", &choice);

        switch (choice){
            case 0: return;
            case 1: do {
                        printf("请输入总人数: ");
                        scanf("%d", &n);
                    } while (n <= 0);

                    do {
                        printf("请输入报数: ");
                        scanf("%d", &k);
                    } while (k <= 0);

                    result = JosephRing(n, k) + 1;
                    printf("幸存者是: %d\n", result);
                    break;

            case 2: do {
                        printf("请输入筛选素数范围的最大值(小于1000的正整数): ");
                        scanf("%d", &n);
                       } while (n <= 0 || n > 1000);

                    int *prime = SievePrime(n);
                    for (int i = 2; i <= n; i++){
                        if(prime[i]){
                            printf("%d ", i);
                        }
                    }
                    printf("\n");
                    break;
        }
    }
}

int JosephRing(int n, int k) {
    if (n == 1){
        return 0;
    }
    else {
        return ((JosephRing(n-1, k) + k) % n);
    }
}

int *SievePrime(int n) {
    static int prime[MaxSize];
    if (n >= MaxSize) {
        n = MaxSize - 1;
    }
    for (int i = 0; i <= n; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    return prime;
}