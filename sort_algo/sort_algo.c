/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:56:55 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/19 01:44:05 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algo.h"
#include <fcntl.h>
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_arr(int *arr, int len)
{
    int i;

    i = 0;
    while (i < len)
        printf("%d ", arr[i++]);
    printf("\n");
}

int is_sort(int *arr, int len)
{
    int i;
    int j;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if(arr[i] > arr[j])
            {
                printf(CRED"array is not sorted\n"CRESET);
                return (0);
            }
            j++;
        }
        i++;
    }
    printf(CGREEN"array is sorted\n"CRESET);
    return(1);
}

void ft_swap(int *i, int *j)
{
    int tmp;
    
    tmp = *i;
    *i = *j;
    *j = tmp;
}


int ft_partition(int *arr, int start, int end)
{
    int i;
    int j;
    int pivot;

    i = start;
    j = end ;
    pivot = arr[(start + end) / 2];
    while (1)
    {

        while(i < end && arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if (i >= j)
            return(j);
        printf("swap arr[i]: %d et arr[j]: %d pivot: %d\n", arr[i], arr[j], pivot);
        
        ft_swap(&arr[i] , &arr[j]);
        i++;
        j--;
        

    }
    return (j);
}

void ft_quicksort(int *arr, int start, int end)
{
    int index_p;

    if (start < end)
    {
        index_p = ft_partition(arr, start, end);
        ft_quicksort(arr, 0, index_p);
        ft_quicksort(arr, index_p + 1, end);
    }

}



int main(void)
{
    //problematique suite parfois arr[i] == arr[j] == pivot
    int arr[] = {   0, -1, 1, 2147483647, -2147483648, 42, -1000, 1000, 5, 4, 3, 2, 1,             
                    1, 2, 3, 4, 5, -50, -20, -20, -1, 9999, -9999, 7, 7, 8, 8, 9, 9, 100, 
                    -100, 13, -13, 500, 0, -500, 2147483646, -2147483647, 3, 3, 2, 2, 1, 1,
                    123456, -123456, 10, -10, 6, 5, 4, 3, 2, 1, 8, 16, 32, 64, 128, 256,
                    -2, -3, -4, -5, 17, 19, 23, 29, 1000000, -1000000
    };
    //int arr[] = { 12, 1, 21, 53, -10, 7, 29, 3};
    //int arr[] = { 291, 729, 15, -404, 448, 526, 810, -785, 411, 963, 363, 986, 898, 459, 875, -20, 26, 550, 707, 541, 694,
    //907, 955, 352, 685, 972, 634, 987, 701, 782, 165, 210, 332, 496, 784, 249, 177};
    ft_quicksort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    is_sort(arr,sizeof(arr) / sizeof(arr[0]));
    //print_arr(arr, sizeof(arr) / sizeof(arr[0]));

    
    return (0);
}