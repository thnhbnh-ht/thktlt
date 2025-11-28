#include<stdio.h>
#include<math.h>
typedef double db;
void nhap(db a[][100], int n){
    int i, j;
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            scanf("%lf", &a[i][j]);
        }
    }
}
void xuat(db a[][100], int n){
    int i, j;
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}
void swap (db *a, db *b){
    db tmp=*a;
    *a=*b;
    *b=tmp;
}
db gauss(db a[][100], int n){
	int i, j, k, r;
	db tmp[100][100];
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tmp[i][j]=a[i][j];
		}
	}
	db det_gauss=1;
	for (i=0;i<n;++i){      
	    k=-1;
	    for (j=i;j<n;++j){
	        if (tmp[j][i]!=0){
	            k=j;
	            break;
	        }
	    }
	    if (k==-1) continue;
	    if (k!=i){
	        for (j=0;j<n;++j){
	            swap(&tmp[i][j], &tmp[k][j]);
	        }
	    }
	    for (r=i+1;r<n;++r){
	        db x=-tmp[r][i]/tmp[i][i];
	        int c;
	        for (c=0;c<n;++c){
	            tmp[r][c]+=x*tmp[i][c];
	        }
	    }
	}
	for (i=0;i<n;++i){
		det_gauss*=tmp[i][i];
	}
	return det_gauss;
}
db phan_ra_LU(db a[][100], int n){
	int i, j, k;
	db temp[100][100];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=a[i][j];
		}
	}
	db l[100][100], u[100][100];
	for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            if (i==j) l[i][j]=1.00;
			else l[i][j]=0.00;
            u[i][j]=0.00;
        }
    }
    for (i=0;i<n;++i){
        for (j=i;j<n;++j){
            db sum=0;
            for (k=0;k<i;++k){
                sum+=l[i][k]*u[k][j];
			}
            u[i][j]=temp[i][j]-sum;
        }
        for (j=i+1;j<n;++j){
           db sum=0;
            for (k=0;k<i;k++){
                sum+=l[j][k]*u[k][i];
			}
            l[j][i]=(temp[j][i]-sum)/u[i][i];
        }
    }
	db det_L=1, det_U=1;
	for (i=0;i<n;++i){
		det_L*=l[i][i];
		det_U*=u[i][i];
	}
	return det_L*det_U;
}
int doi_xung(db a[][100], int n){
	int i, j;
	for (i=0;i<n;++i){
		for (j=i+1;j<n;++j){
			if (a[i][j]!=a[j][i]) return 0;
		}
	}
	return 1;
}
int duong(db a[][100], int n){
	int i, j, k;
	for (i=2;i<=n;++i){
		db b[100][100];
		for (j=0;j<i;++j){
			for (k=0;k<i;++k){
				b[j][k]=a[j][k];
			}
		} 
		if (gauss(b, i)<0) return 0;
	}
	return 1;
}
db Cholesky(db a[][100], int n){
	if (duong(a, n) && (doi_xung(a, n))){
		db l[100][100];
		int i, j, k;
		for (i=0;i<n;++i){
        	for (j=0;j<=i;++j){
            	db sum=0;
            	for (k=0;k<j;++k)
                	sum+=l[i][k]*l[j][k];
            	if (i==j) {
                	l[i][i]=sqrt(a[i][i]-sum);  
            	} else {
                	l[i][j]=(a[i][j]-sum)/l[j][j];
            	}
        	}
    	}
		db det_Cholesky=1;
		for (i=0;i<n;++i){
			det_Cholesky*=l[i][i];
		}
		return det_Cholesky*det_Cholesky;
	}
	else printf("Ma tran khong doi xung duong nen khong the dung phuong phap Cholesky\n");
	return 0.00;
}
db Laplace(db a[][100], int n, int pick){
	if (n==1) return a[0][0];
	if (n==2) return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	
	db m[100][100], det_laplace=0;
	int i, r, c, row, col;
	int dau=1;
	for (i=0;i<n;++i){
	    if (a[pick][i]==0) continue;
	    row=0;
    	for (r=0;r<n;++r){
    	    if (r==pick) continue;
    	    col=0;
    	    for (c=0;c<n;++c){
    	        if (c==i) continue;
    	        m[row][col]=a[r][c];
				++col;
    	    }
    	    ++row;
    	}
    	det_laplace+=dau*a[pick][i]*Laplace(m, n-1, pick);
    	dau=-dau;
   	}
	return det_laplace;
}
db Laplace_cai_tien(db a[][100], int n){
	int i, j, cnt, pick, max=-1;
	for (i=0;i<n;++i){
		cnt=0;
		for (j=0;j<n;++j){
			if(a[i][j]==0) ++cnt;
		}
		if (cnt>max){
			max=cnt;
			pick=i;
		}
	}
	return -Laplace(a, n, pick);
}
void ma_tran_con(db a[][100],db m[][100], int i, int j, int n){
	int row=0, r, col, c;
    for (r=0;r<n;++r){
    	if (r==i) continue;
    	int col=0;
    	for (c=0;c<n;++c){
    	    if (c==j) continue;
    	    m[row][col]=a[r][c];
			++col;
    	}
    	++row;
    }
}                      
db phan_bu(db a[][100], int i, int j, int n){
	db tmp[100][100];
    ma_tran_con(a, tmp, i, j, n);
    db det=gauss(tmp, n-1);
    if ((i+j)&1) det=-det; 
    return det;
}
void phu_hop(db a[][100], db ph[][100], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ph[i][j] = phan_bu(a, i, j, n);
        }
    }
}
void nghich_dao(db a[][100], db matrix[][100], int n){
	int i, j;
	db temp[100][100];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=a[i][j];
		}
	}
	db det=gauss(temp,n);
	if (det==0){
		printf ("Khong ton tai ma tran nghich dao\n");
	}
	else{
		db ph[100][100];
		phu_hop(a, ph, n);
		for (i=0;i<n;++i){
			for (j=0;j<n;++j){
				matrix[i][j]=ph[j][i]/det;
			}
		}
		xuat(matrix,n);
	}
}
int main(){
    int n;
    scanf("%d", &n);
    db a[n][n], matrix[n][n];
    nhap(a, n);
    xuat(a, n);
	printf("Tinh dinh thuc bang phuong phap khu Gauss: %.2lf\n", gauss(a, n));

	printf("Tinh dinh thuc bang phuong phap phan ra LU: %.2lf\n", phan_ra_LU(a, n));

	printf("Tinh dinh thuc bang phuong phap Cholesky: %.2lf\n", Cholesky(a, n));
	
	printf("Tinh dinh thuc bang phuong phap Laplace: %.2lf\n", Laplace(a, n, 0));
	
	printf("Tinh dinh thuc bang phuong phap Laplace cai tien: %.2lf\n", Laplace_cai_tien(a, n));

	printf("Ma tran nghich dao cua A:\n");
	nghich_dao(a,matrix,n);
}