// 提示：考试时默认栈的结构体 SqStack 以及基本操作（InitStack, Push, Pop）已经定义好了
int isPalindrome(char str[], int length) {
    SqStack S;
    InitStack(&S); // 1. 初始化一个空栈
    
    int i;
    // 2. 将前半段字符依次压入栈中
    for (i = 0; i < length / 2; i++) {
        Push(&S, str[i]);
    }
    
    // 🔥【核心加分点】3. 如果字符串长度是奇数，跳过正中间那个字符
    if (length % 2 != 0) {
        i++; 
    }
    
    // 4. 遍历后半段字符，每走一步，弹栈一次进行对比
    while (i < length) {
        char topChar;
        Pop(&S, &topChar); // 弹出栈顶字符
        
        if (str[i] != topChar) {
            return 0; // 只要有一个字符对不上，立即判定：不是回文！
        }
        i++;
    }
    
    return 1; // 5. 顺利走到最后，说明全部匹配，判定：是回文！
}