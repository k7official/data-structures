#include<iostream>
int class_test_average(int test1, int test2, int test3);
char compute_grade(int score);

int main()
{
    int T;
    std::cin >> T;
    int counter = 0;
    const int total_term1 = 20;
    const int total_term2 = 20;
    const int total_final = 30;
    const int total_attendance = 10;
    const int total_class_test = 20;
    
    while(counter < T)
    {
        int term_1;
        int term_2;
        int final_;
        int attendance;
        int class_test1;
        int class_test2;
        int class_test3;
        int test_average;
        int total_score;
        char grade;

        std::cin >> term_1 >> term_2 >> final_ >> attendance >> class_test1 >> class_test2 >> class_test3;
        test_average = class_test_average(class_test1, class_test2, class_test3);
        total_score = term_1 + term_2 + final_ + attendance + test_average;
        grade = compute_grade(total_score);

        std::cout << "Case " << counter+1 << ": " << grade << std::endl;
        counter++;
    }

    return 0;
}

int class_test_average(int test1, int test2, int test3)
{
    int average;
    if(test1 > test2 || test1 > test3)
    {
        if(test2 > test3)
            average = (test1 + test2) / 2;
        else average = (test1 + test3) / 2;
    }
    else{
        average = (test2 + test3) / 2;
    }

    return average;
}
char compute_grade(int score)
{
    char grade;
    if(score >= 90)
        grade = 'A';
    else if(score >= 80)
        grade = 'B';
    else if(score >= 70)
        grade = 'C';
    else if(score >= 60)
        grade = 'D';
    else grade = 'F';

    return grade;
}