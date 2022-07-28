
int math_add(int n1, int n2)
{
    return n1 + n2;
}

int math_sub(int n1, int n2)
{
    return n1 - n2;
}

long long int math_mul(int n1, int n2)   // will not return a long long int value although we defined it as such. Because we are multiplying integers. We need to use typecasting!
{
    return (long long int)n1 * n2;   // This is explicit typecasting! We will see implicit type casting later! Converting only one type is enough!
}

float math_div(int n1, int n2)     // will not return a float value although we defined it as such. Because we are deviding integers. We need to use typecasting!
{
    return (float)n1 / n2;          // This is explicit typecasting! We will see implicit type casting later! Converting only one type is enough!
}