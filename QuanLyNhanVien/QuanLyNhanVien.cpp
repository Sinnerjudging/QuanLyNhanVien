#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct nv {
    string maNV;
    string hoten;
    string date;
    string chucvu;
    string diachi;
    string sodt;
    string songaycong;
    string luongngay;
    string thuclinh;
} nv;

struct node_nv {
    nv data;
    node_nv* pnext;
};

typedef struct danh_sach_nv {
    node_nv* phead = NULL;
    node_nv* ptail = NULL;
} danh_sach_nv;

void menu();
istream& operator >> (istream& is, nv& a);
node_nv* khoi_tao_node(nv x);
void them(danh_sach_nv& ds_nv, nv x);
void xuat(danh_sach_nv ds_nv);
void load_file(danh_sach_nv& ds_nv);
void xoa_nv(danh_sach_nv& ds_nv, string vt);
void tim_nv(danh_sach_nv ds_nv, string maNV);
void xuat_nv_thuclinh_thap_nhat(danh_sach_nv ds_nv);
void sap_xep_nv_thuclinh_tang_dan(danh_sach_nv& ds_nv);
void doc_file(danh_sach_nv& ds_nv);
void ghi_file(danh_sach_nv& ds_nv);

int main() {
    menu();
}

void menu() {
    danh_sach_nv ds_nv;
    load_file(ds_nv);
    bool kt = true;
    while (kt) {
        system("cls");
        cout << "1. Nhap nhan vien" << endl;
        cout << "2. Xuat danh sach nhan vien" << endl;
        cout << "3. Xoa nhan vien theo ma" << endl;
        cout << "4. Tim nhan vien theo ma" << endl; 
        cout << "5. Xuat danh sach nhan vien có thuc linh thap nhat ra man hinh" << endl;
        cout << "6. Sap xep danh sach nhan vien tang dan theo thuc linh" << endl;
        cout << "7. Doc danh sach nhan vien tu file" << endl;
        cout << "8. Ghi danh sach nhan vien ra file" << endl;
        cout << "0. Thoat" << endl;
        int lc;
        cout << "Nhap lua chon: "; cin >> lc;
        switch (lc) {
        case 1: {
            int sl;
            cout << "Nhap so luong nhan vien can them: ";
            cin >> sl;
            cin.ignore();
            for (int i = 1; i <= sl; i++) {
                cout << "\t\t------ Nhap NV " << i << " ------" << endl;
                nv x;
                cin >> x;
                them(ds_nv, x);
            }
            break;
        }
        case 2: {
            xuat(ds_nv);
            system("pause");
            break;
        }
        case 3: {
            string vt;
            cin.ignore();
            cout << "Nhap ma nhan vien can xoa: ";
            getline(cin, vt);
            xoa_nv(ds_nv, vt);
            system("pause");
            break;
        }
        case 4: {
            string maNV;
            cin.ignore();
            cout << "Nhap ma nhan vien can tim: ";
            getline(cin, maNV);
            tim_nv(ds_nv, maNV);
            system("pause");
            break;
        }
        case 5: {  
            xuat_nv_thuclinh_thap_nhat(ds_nv);
            system("pause");
            break;
        }
        case 6: {
            sap_xep_nv_thuclinh_tang_dan(ds_nv);
            cout << "Danh sach nhan vien sau khi sap xep:" << endl;
            xuat(ds_nv);
            system("pause");
            break;
        }
        case 7: {
            xuat(ds_nv);
            system("pause");
            break;
        }

        case 8: {
            ghi_file(ds_nv);
            cout << "Da ghi danh sach nhan vien ra file." << endl;
            system("pause");
            break;
        }

        case 0: {
            kt = false;
            break;
        }
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    }
}

istream& operator >> (istream& is, nv& a) {
    cout << "Nhap ma nhan vien: "; getline(is, a.maNV);
    cout << "Nhap ho ten: "; getline(is, a.hoten);
    cout << "Nhap ngay thang sinh: "; getline(is, a.date);
    cout << "Nhap chuc vu: "; getline(is, a.chucvu);
    cout << "Nhap dia chi lien lac: "; getline(is, a.diachi);
    cout << "Nhap so dien thoai: "; getline(is, a.sodt);
    cout << "Nhap so ngay cong lam viec trong thang: "; getline(is, a.songaycong);
    cout << "Nhap luong ngay: "; getline(is, a.luongngay);
    cout << "Nhap thuc linh: "; getline(is, a.thuclinh);
    return is;
}

node_nv* khoi_tao_node(nv x) {
    node_nv* p = new node_nv;
    p->data = x;
    p->pnext = NULL;
    return p;
}

void them(danh_sach_nv& ds_nv, nv x) {
    node_nv* p = khoi_tao_node(x);
    if (ds_nv.phead == NULL) {
        ds_nv.phead = ds_nv.ptail = p;
    }
    else {
        ds_nv.ptail->pnext = p;
        ds_nv.ptail = p;
    }
}

void xuat(danh_sach_nv ds_nv) {
    int i = 1;
    for (node_nv* k = ds_nv.phead; k != NULL; k = k->pnext) {
        cout << "\t\t------ NV " << i++ << " ------" << endl;
        cout << "Ma nhan vien: " << k->data.maNV << endl;
        cout << "Ho ten: " << k->data.hoten << endl;
        cout << "Ngay thang sinh: " << k->data.date << endl;
        cout << "Chuc vu: " << k->data.chucvu << endl;
        cout << "Dia chi lien lac: " << k->data.diachi << endl;
        cout << "so dien thoai: " << k->data.sodt << endl;
        cout << "So ngay cong lam viec: " << k->data.songaycong << endl;
        cout << "Luong ngay: " << k->data.luongngay << endl;
        cout << "Thuc linh: " << k->data.thuclinh << endl;
        cout << "-----------------------------------" << endl;
    }
}

void load_file(danh_sach_nv& ds_nv) {
    ifstream filein("input.txt");
    if (!filein.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    while (!filein.eof()) {
        nv a;
        getline(filein, a.maNV, ',');
        getline(filein, a.hoten, ',');
        getline(filein, a.date, ',');
        getline(filein, a.chucvu, ',');
        getline(filein, a.diachi, ',');
        getline(filein, a.sodt, ',');
        getline(filein, a.songaycong, ',');
        getline(filein, a.luongngay, ',');
        getline(filein, a.thuclinh);
        if (!a.maNV.empty())
            them(ds_nv, a);
    }
    filein.close();
}

void xoa_nv(danh_sach_nv& ds_nv, string vt) {
    node_nv* h = NULL;
    node_nv* k = ds_nv.phead;
    while (k != NULL) {
        if (k->data.maNV == vt) {
            if (k == ds_nv.phead) {
                ds_nv.phead = ds_nv.phead->pnext;
                delete k;
                k = ds_nv.phead;
            }
            else {
                h->pnext = k->pnext;
                if (k == ds_nv.ptail) {
                    ds_nv.ptail = h;
                }
                delete k;
                k = h->pnext;
            }
        }
        else {
            h = k;
            k = k->pnext;
        }
    }
}

void tim_nv(danh_sach_nv ds_nv, string maNV) {
    for (node_nv* k = ds_nv.phead; k != NULL; k = k->pnext) {
        if (k->data.maNV == maNV) {
            cout << "\t\t------ Thong tin nhan vien ------" << endl;
            cout << "Ma nhan vien: " << k->data.maNV << endl;
            cout << "Ho ten: " << k->data.hoten << endl;
            cout << "Ngay thang sinh: " << k->data.date << endl;
            cout << "Chuc vu: " << k->data.chucvu << endl;
            cout << "Dia chi lien lac: " << k->data.diachi << endl;
            cout << "So dien thoai: " << k->data.sodt << endl;
            cout << "So ngay cong lam viec: " << k->data.songaycong << endl;
            cout << "Luong ngay: " << k->data.luongngay << endl;
            cout << "Thuc linh: " << k->data.thuclinh << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << maNV << endl;
}

void xuat_nv_thuclinh_thap_nhat(danh_sach_nv ds_nv) {
    if (ds_nv.phead == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    node_nv* k = ds_nv.phead;
    double minluong = -1; 
    nv minluongnv; 
    bool found = false;

  
    for (k = ds_nv.phead; k != NULL; k = k->pnext) {
        if (!k->data.thuclinh.empty()) {
            try {
                double luong = stod(k->data.thuclinh);
                if (minluong == -1 || luong < minluong) {
                    minluong = luong;
                    minluongnv = k->data; // Store the employee with the new minimum salary
                    found = true; // A valid employee was found
                }
            }
            catch (const invalid_argument&) {
                cout << "Loi: Thuc linh cua nhan vien " << k->data.maNV << " khong hop le." << endl;
            }
        }
    }


    if (!found) {
        cout << "Khong co nhan vien nao co thuc linh hop le!" << endl;
        return;
    }


    cout << "\t\t--- Nhan vien co thuc linh thap nhat ---" << endl;
    cout << "Ma nhan vien: " << minluongnv.maNV << endl;
    cout << "Ho ten: " << minluongnv.hoten << endl;
    cout << "Ngay thang sinh: " << minluongnv.date << endl;
    cout << "Chuc vu: " << minluongnv.chucvu << endl;
    cout << "Dia chi lien lac: " << minluongnv.diachi << endl;
    cout << "So dien thoai: " << minluongnv.sodt << endl;
    cout << "Luong ngay: " << minluongnv.luongngay << endl;
    cout << "Thuc linh: " << minluongnv.thuclinh << endl;
    cout << "-----------------------------------" << endl;
}

void sap_xep_nv_thuclinh_tang_dan(danh_sach_nv& ds_nv) {
    if (ds_nv.phead == NULL) {
        return;
    }

    for (node_nv* k = ds_nv.phead; k != NULL; k = k->pnext) {
        for (node_nv* j = k->pnext; j != NULL; j = j->pnext) {
            if (stod(k->data.thuclinh) > stod(j->data.thuclinh)) {
                nv temp = k->data;
                k->data = j->data;
                j->data = temp;
            }
        }
    }
}

void doc_file(danh_sach_nv& ds_nv) {
    ifstream filein("input.txt");
    if (!filein.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    while (!filein.eof()) {
        nv a;
        getline(filein, a.maNV, ',');
        getline(filein, a.hoten, ',');
        getline(filein, a.date, ',');
        getline(filein, a.chucvu, ',');
        getline(filein, a.diachi, ',');
        getline(filein, a.sodt, ',');
        getline(filein, a.songaycong, ',');
        getline(filein, a.luongngay, ',');
        getline(filein, a.thuclinh);
        if (!a.maNV.empty())
            them(ds_nv, a);
    }
    filein.close();
}

void ghi_file(danh_sach_nv& ds_nv) {
    ofstream fileout("output.txt");
    if (!fileout.is_open()) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }
    for (node_nv* k = ds_nv.phead; k != NULL; k = k->pnext) {
        fileout << k->data.maNV << ","
            << k->data.hoten << ","
            << k->data.date << ","
            << k->data.chucvu << ","
            << k->data.diachi << ","
            << k->data.sodt << ","
            << k->data.songaycong << ","
            << k->data.luongngay << ","
            << k->data.thuclinh << endl;
    }
    fileout.close();
}