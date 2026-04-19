/*
Name: RWOTOMIA PIUS EMMANUEL 
Registration Number: 25/U/BIE/01419/PE
*/

#include <stdio.h>
#include <stdlib.h>
const char* grade(float score) {
    if (score>=80) return "A";
    else if(score>=70) return "B";
    else if(score>=60) return "C";
    else if(score>=50) return "D";
    else return "F";
}
float gradePoint(float score) {
    if (score>=80) return 5.0;
    else if(score>=70) return 4.0;
    else if(score>=60) return 3.0;
    else if(score>=50) return 2.0;
    else return 0.0;
}
const char* classification(float cgpa) {
    if (cgpa>=4.40) return "First Class";
    else if(cgpa>=3.60) return "Second Class Upper";
    else if(cgpa>=2.80) return "Second Class Lower";
    else if(cgpa>=2.00) return "Pass";
    else return "Fail";
}
 void printLine() {
     printf("==========================\n");
 }
 void printThinLine() {
     printf("--------------------------\n");
 }
 
int main() {
    char sem1_courseCode[8][12] = { "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108" };
    char sem2_courseCode[8][12] = { "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208" };
    float sem1_scores[8], sem2_scores[8], sem1_gp[8], sem2_gp[8], sem1_weightedContribution[8], sem2_weightedContribution[8];
    int sem1_creditUnits[8] = {4, 3, 3, 3, 3, 3, 2, 3};
    int sem2_creditUnits[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    printLine();
    printf("SEMESTER ONE - SCORE ENTRY\n");
    printLine();
    printf("  %-12s  %s\n", "courseCode",  "score");
    
    printThinLine();
    float sem1_totalWeightedContribution = 0;
    int   sem1_totalCreditUnits  = 0;

    for (int i = 0; i < 8; i++) {
        printf("  %-12s : ", sem1_courseCode[i]);
        scanf("%f", &sem1_scores[i]);

   if (sem1_scores[i] < 0 ||sem1_scores[i] > 100) {
        printf("Invalid score entered\n");
            return 1;
}

    sem1_gp[i] = gradePoint(sem1_scores[i]);
    sem1_weightedContribution[i] = sem1_gp[i] * sem1_creditUnits[i];
    sem1_totalWeightedContribution += sem1_weightedContribution[i]; 
    sem1_totalCreditUnits += sem1_creditUnits[i];
    }

    float sem1_GPA = sem1_totalWeightedContribution / sem1_totalCreditUnits;
    
    printf("\n");
    printLine();
    printf("SEMESTER TWO - SCORE ENTRY\n");
    printLine();
    printf("  %-12s  %s\n", "courseCode", "score");
    printThinLine();
    float sem2_totalWeightedContribution = 0;
    int sem2_totalCreditUnits = 0;
    for (int i = 0; i < 8; i++) {
        printf("  %-12s : ", sem2_courseCode[i]);
        scanf("%f", &sem2_scores[i]);

    if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
    }

        sem2_gp[i] = gradePoint(sem2_scores[i]);
        sem2_weightedContribution[i] = sem2_gp[i] * sem2_creditUnits[i];
        sem2_totalWeightedContribution += sem2_weightedContribution[i];
        sem2_totalCreditUnits  += sem2_creditUnits[i];
    }

   float sem2_GPA = sem2_totalWeightedContribution / sem2_totalCreditUnits;
   float totalWeightedContribution = sem1_totalWeightedContribution + sem2_totalWeightedContribution;
   int   totalCreditUnits = sem1_totalCreditUnits  + sem2_totalCreditUnits;
   float CGPA = totalWeightedContribution / totalCreditUnits;
   
   printf("\n\n");
   printLine();
   printf("KYAMBOGO UNIVERSITY ACADEMIC REPORT - YEAR 1\n");
   printf("Bachelors of Engineering in Biomedical and Mechatronics \n");
    
   printLine();
   printf("\n  SEMESTER ONE RESULTS\n");
   printThinLine();
   printf("  %-12s  %-7s  %-6s  %-11s  %-11s  %-14s\n",
           "courseCode", "score", "grade",
           "gradePoint", "creditUnits", "weightedContribution");
           
   printThinLine();
    for (int i = 0; i < 8; i++) {
        printf("  %-12s  %-7.2f  %-6s  %-11.1f  %-11d  %.2f\n",
    sem1_courseCode[i], sem1_scores[i], grade(sem1_scores[i]), sem1_gp[i], sem1_creditUnits[i], sem1_weightedContribution[i]);
    }

   printThinLine();
   printf("  Total Credit Units : %d\n", sem1_totalCreditUnits);
   printf("  Total Weighted Contribution : %.2f\n", sem1_totalWeightedContribution);

   printf("\nSEMESTER TWO RESULTS\n");
   printThinLine();
   printf("  %-12s  %-7s  %-6s  %-11s  %-11s  %-14s\n","courseCode", "score", "grade", "gradePoint","creditUnit","weightedContribution");
    
   printThinLine();
    for (int i = 0; i < 8; i++) {
     printf("  %-12s  %-7.2f  %-6s  %-11.1f  %-11d  %.2f\n",sem2_courseCode[i],sem2_scores[i],grade(sem2_scores[i]),sem2_gp[i],sem2_creditUnits[i],
        sem2_weightedContribution[i]);
    }

   printThinLine();
   printf("  Total Credit Units : %d\n", sem2_totalCreditUnits);
   printf("  Total Weighted Contribution : %.2f\n", sem2_totalWeightedContribution);
    
   printf("\n");
   printLine();
   printf("Semester One GPA: %.2f\n", sem1_GPA);
   printf("Semester Two GPA: %.2f\n", sem2_GPA);
   printf("Cumulative GPA: %.2f\n", CGPA);
   printf("Academic Classification: %s\n", classification(CGPA));
   printLine();

    return 0;
}
