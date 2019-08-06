    /* Fibonacci series program in C language */
    #include <stdio.h>
     
    int main()
    {
      int n, first = 0, second = 1, next, c;
     
      printf("Enter a number: ");
      scanf("%d", &n);
     
      printf("First %d Fibonacci numbers  are: ", n);
     
      for (c = 0; c < n; c++)
      {
        if (c <= 1)
          next = c;
        else
        {
          next = first + second;
          first = second;
          second = next;
        }
        printf("%d, ", next);
      }
     
      return 0;
    }


