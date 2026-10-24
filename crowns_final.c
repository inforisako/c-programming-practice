#include "crowns.h"
#define REGION_COUNT_SIZE 256


void test(void)
{
 board a ;
 a.sze = 5;
  
 a.cs[0][0].mark = unknown;
 a.cs[0][1].mark = unknown;
 a.cs[0][2].mark = unknown;
 a.cs[0][3].mark = unknown;
 a.cs[0][4].mark = unknown;
 a.cs[1][0].mark = cross;
 a.cs[1][1].mark = cross;
 a.cs[1][2].mark = cross;
 a.cs[1][3].mark = cross;
 a.cs[1][4].mark = cross;
 a.cs[2][0].mark = unknown;
 a.cs[2][1].mark = unknown;
 a.cs[2][2].mark = unknown;
 a.cs[2][3].mark = unknown;
 a.cs[2][4].mark = unknown;
 a.cs[3][0].mark = crown;
 a.cs[3][1].mark = crown;
 a.cs[3][2].mark = crown;
 a.cs[3][3].mark = crown;
 a.cs[3][4].mark = crown;
 a.cs[4][0].mark = crown;
 a.cs[4][1].mark = crown;
 a.cs[4][2].mark = crown;
 a.cs[4][3].mark = crown;
 a.cs[4][4].mark = crown;

 assert(count_unknowns(a) == 10);
 

 board game;
 board* b = &game;
 b->sze = 7;

 b->cs[0][0].region = 'A';
 b->cs[0][0].mark = unknown;

 b->cs[0][1].region = 'A';
 b->cs[0][1].mark = unknown;

 b->cs[0][2].region = 'B';
 b->cs[0][2].mark = unknown;

 b->cs[0][3].region = 'B';
 b->cs[0][3].mark = unknown;

 b->cs[0][4].region = 'B';
 b->cs[0][4].mark = crown;;

 b->cs[0][5].region = 'B';
 b->cs[0][5].mark = unknown;

 b->cs[0][6].region = 'B';
 b->cs[0][6].mark = unknown; 


 b->cs[1][0].region = 'A';
 b->cs[1][0].mark = unknown;

 b->cs[1][1].region = 'A';
 b->cs[1][1].mark = unknown;

 b->cs[1][2].region = 'B';
 b->cs[1][2].mark = unknown;

 b->cs[1][3].region = 'B';
 b->cs[1][3].mark = unknown;

 b->cs[1][4].region = 'B';
 b->cs[1][4].mark = unknown;

 b->cs[1][5].region = 'B';
 b->cs[1][5].mark = unknown;
 b->cs[1][6].region = 'B';
 b->cs[1][6].mark = unknown;

 b->cs[2][0].region = 'A';
 b->cs[2][0].mark = crown;

 b->cs[2][1].region = 'C';
 b->cs[2][1].mark = unknown;

 b->cs[2][2].region = 'C';
 b->cs[2][2].mark = unknown;

 b->cs[2][3].region = 'C';
 b->cs[2][3].mark = unknown;

 b->cs[2][4].region = 'C';
 b->cs[2][4].mark = unknown;

 b->cs[2][5].region = 'C';
 b->cs[2][5].mark = unknown;

 b->cs[2][6].region = 'E';
 b->cs[2][6].mark = unknown;

 b->cs[3][0].region = 'D';
 b->cs[3][0].mark = unknown;

 b->cs[3][1].region = 'D';
 b->cs[3][1].mark = unknown;

 b->cs[3][2].region = 'D';
 b->cs[3][2].mark = unknown;

 b->cs[3][3].region = 'D';
 b->cs[3][3].mark = unknown;

 b->cs[3][4].region = 'C';
 b->cs[3][4].mark = unknown;

 b->cs[3][5].region = 'C';
 b->cs[3][5].mark = crown;

 b->cs[3][6].region = 'E';
 b->cs[3][6].mark = unknown;

 b->cs[4][0].region = 'D';
 b->cs[4][0].mark = unknown;

 b->cs[4][1].region = 'D';
 b->cs[4][1].mark = crown;

 b->cs[4][2].region = 'D';
 b->cs[4][2].mark = unknown;

 b->cs[4][3].region = 'D';
 b->cs[4][3].mark = unknown;

 b->cs[4][4].region = 'C';
 b->cs[4][4].mark = unknown;

 b->cs[4][5].region = 'C';
 b->cs[4][5].mark = unknown;

 b->cs[4][6].region = 'E';
 b->cs[4][6].mark = unknown;

 b->cs[5][0].region = 'D';
 b->cs[5][0].mark = unknown;

 b->cs[5][1].region = 'D';
 b->cs[5][1].mark = unknown;

 b->cs[5][2].region = 'D';
 b->cs[5][2].mark = unknown;

 b->cs[5][3].region = 'D';
 b->cs[5][3].mark = unknown;

 b->cs[5][4].region = 'E';
 b->cs[5][4].mark = unknown;

 b->cs[5][5].region = 'E';
 b->cs[5][5].mark = unknown;

 b->cs[5][6].region = 'E';
 b->cs[5][6].mark = crown;

 b->cs[6][0].region = 'F';
 b->cs[6][0].mark = unknown;

 b->cs[6][1].region = 'F';
 b->cs[6][1].mark = unknown;

 b->cs[6][2].region = 'F';
 b->cs[6][2].mark = crown;

 b->cs[6][3].region = 'F';
 b->cs[6][3].mark = unknown;

 b->cs[6][4].region = 'F';
 b->cs[6][4].mark = unknown;

 b->cs[6][5].region = 'F';
 b->cs[6][5].mark = unknown;

 b->cs[6][6].region = 'E';
 b->cs[6][6].mark = unknown;
 
 assert(b->sze == 7);
 assert(b->cs[0][0].region == 'A');
 assert(b->cs[0][1].mark == unknown);

}





bool str2board(board* b, char* str)
{
    if (b == NULL || str == NULL) {
        return false;
    }

    int i = 0;

    while (str[i] != '|' && str[i] != '\0') {
        i++;
    }

    int size = i / 2;

    if (i % 2 != 0 || size == 0 || size > MXBSIZE) {
        return false;
    }

    int pos = 0;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {

            if (str[pos] == '\0' ||
                str[pos] == '|' ||
                str[pos + 1] == '\0') {
                return false;
            }

            if (str[pos + 1] != ' ' &&
                str[pos + 1] != 'X' &&
                str[pos + 1] != '*') {
                return false;
            }

            b->cs[row][col].region = str[pos];
            b->cs[row][col].mark = (validmarks)str[pos + 1];

            pos += 2;
        }

        if (row < size - 1) {
            if (str[pos] != '|') {
                return false;
            }
            pos++;
        }
    }

    if (str[pos] != '\0') {
        return false;
    }

    b->sze = size;

    return true;
}





bool board2str(char* str, const board* b){
   if (b == NULL || str == NULL) {
        return false;
   }

   int pos = 0;

   for ( int row = 0; row < b->sze; row++){
       for (int col = 0; col< b->sze; col++){

           str[pos] = b->cs[row][col].region;
           str[pos + 1] = (char)b->cs[row][col].mark;

            pos += 2;
       }

   if (row < b->sze - 1) {
    str[pos] = '|';
    pos++;
   }
   }

 str[pos] = '\0';

return true;
}





int count_unknowns(board b){
  int count = 0;
  for (int row = 0; row < b.sze; row++) {
    for (int col = 0; col < b.sze; col++) {
        if ( b.cs[row][col].mark == unknown) {
    count++;

        }
    }
   }
return count;
}





bool rule1(board* b){
 if (b == NULL){
     return false;
 }

 bool changed = false;

 for (int row = 0; row< b ->sze; row++){
     for (int col = 0; col< b ->sze; col++){
           if (b->cs[row][col].mark == crown){

               for (int r = 0; r < b ->sze; r++){
                for (int c = 0; c < b ->sze; c++){

                  if ((row == r ||
                       col == c ||
                       b ->cs[row][col].region == b ->cs[r][c].region ||
                       (abs(row - r) <= 1 && abs(col - c) <= 1)) &&
                       b ->cs[r][c].mark == unknown) {
                       b ->cs[r][c].mark = cross;
                       changed = true;
                        }

                }
               }
           }
      }
 }
 return changed;
}






bool rule2(board* b){
    if (b == NULL){
     return false;
    }
 
    if (b->sze < 1 || b->sze > MXBSIZE) {
        return false;
    }

    bool changed = false;
    bool changed_this_pass;

    do{
       changed_this_pass = false;

    for (int row = 0; row < b ->sze; row++){
        int count = 0;
        int target_col = -1;
        bool has_crown = false;  

        for (int col = 0; col < b->sze; col++){
            if (b->cs[row][col].mark == unknown){
                count++;
                target_col = col;
            }

          if (b->cs[row][col].mark == crown) {
              has_crown = true;
          }
        }

        if (count == 1 && !has_crown) {
        b->cs[row][target_col].mark = crown;
        changed = true;
        changed_this_pass = true;
        }
   }



   for (int col = 0; col < b ->sze; col++){
        int count = 0;
        int target_row = -1;
        bool has_crown = false;

        for (int row = 0; row < b->sze; row++){
             if (b->cs[row][col].mark == unknown){
                 count++;
                 target_row = row;
             }
        if (b->cs[row][col].mark == crown) {
            has_crown = true;
        }
        }

       if (count == 1 && !has_crown) {
       b->cs[target_row][col].mark = crown;
       changed = true;
       changed_this_pass = true;

          }
     }
   for (int r = 0; r < b->sze; r++) {
      for (int c = 0; c < b->sze; c++) {

        char target_region = b->cs[r][c].region;
        int count = 0;
        int target_row = -1;
        int target_col = -1;
        bool has_crown = false;

        for (int row = 0; row < b->sze; row++) {
            for (int col = 0; col < b->sze; col++) {

              if (b->cs[row][col].region == target_region) {
                  if (b->cs[row][col].mark == unknown) {
                      count++;
                     target_row = row;
                     target_col = col;
                 }
                 if (b->cs[row][col].mark == crown) {
                     has_crown = true;
                }
             }
          }
       }
     if (count == 1 && !has_crown) {
        b->cs[target_row][target_col].mark = crown;
        changed = true;
        changed_this_pass = true;
     }
   } // for (int c ...)
   } // for (int r ...)
   if (rule1(b)) {
        changed = true;
       changed_this_pass = true;
   }
   } while (changed_this_pass);

   return changed;
}





bool rule3(board* b)
{
 if (b == NULL) {
        return false;
    }

    bool changed = false;
    bool changed_this_pass;

    do {
        changed_this_pass = false;
 
        for (int row = 0; row < b->sze; row++) {
         for (int col = 0; col < b->sze; col++) {

        if (b->cs[row][col].mark == unknown) {       
            board temp = *b;
 
            temp.cs[row][col].mark = crown;

            rule1(&temp);
            for (int r = 0; r < temp.sze; r++) {
                for (int c = 0; c < temp.sze; c++) {

                    if (b->cs[r][c].mark == unknown &&
                        temp.cs[r][c].mark == cross) {

                        char target_region = temp.cs[r][c].region;
                        int count_unknown = 0;
                        int count_crown = 0;

                        for (int i = 0; i < temp.sze; i++) {
                            for (int j = 0; j < temp.sze; j++) {

                                if (temp.cs[i][j].region == target_region) {

                                    if (temp.cs[i][j].mark == unknown) {
                                        count_unknown++;
                                    }

                                    if (temp.cs[i][j].mark == crown) {
                                        count_crown++;
                                    }
                                }
                            }
                        }

                        if (count_unknown == 0 && count_crown == 0) {
                            b->cs[row][col].mark = cross;
                            changed = true;
                            changed_this_pass = true;
                        }
                    }
                }
            }
        }  // if (unknown)
    }      // for (col)
}          // for (row)
} while (changed_this_pass);

    return changed;
}






bool rule5(board* b){

    if (b == NULL) {
        return false;
    }

    int size = b->sze;
    char str[2 * MXBSIZE * MXBSIZE + MXBSIZE];
    int n = 0;

    while (lut(size, n, str)) {
        bool valid = true;
        int region_count[256] = {0};

    for (int row = 0; row < size; row++) {
         int crown_col = str[row] - 'A';

    if (crown_col < 0 || crown_col >= size) {
        valid = false;
        break;
    }

    for (int col = 0; col < size; col++) {
                if (col == crown_col) {
                unsigned char region = b->cs[row][col].region;
                region_count[region]++;
                }
               if (b->cs[row][col].mark == cross &&
               col == crown_col) {
               valid = false;
               }

              if (b->cs[row][col].mark == crown &&
              col != crown_col) {
              valid = false;
              }
            }
        }

      for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {

        unsigned char region = b->cs[row][col].region;

        if (region_count[region] != 1) {
            valid = false;
                }
            }
         }
        if (valid) {
      for (int row = 0; row < size; row++) {
           int crown_col = str[row] - 'A';

      for (int col = 0; col < size; col++) {
        if (col == crown_col) {
          b->cs[row][col].mark = crown;
          } else {
          b->cs[row][col].mark = cross;
          }

                }
            }

            return true;
        }

        n++;
    }

    return false;
}
