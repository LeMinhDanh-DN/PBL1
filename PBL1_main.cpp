#include <iostream>
#include <vector>
using namespace std;

int get_thang(string date){
    return (date[3] - '0') * 10 + (date[4] - '0');
}
int get_ngay(string date){
    return (date[0] - '0') * 10 + (date[1] - '0');
}
int get_nam(string date){
    int year = 0;
    for(int i = 6; i<= 9; i--){
        year = year*10 + (date[i] -'0');
    }
    return year;
}

int trungMaHang(string maGoc, string maBatDau){
    for(int i = 0; i< maBatDau.size() ; i++){
        if(maGoc[i] != maBatDau[i]) return 0;
    }
    return 1;
}

class phieu_nk{
    private:
        string maHang;
        string tenHang;
        string donViTinh;
        string ngayNhap;
        int soLuong;
        double donGia;
        double thanhTien;

    public:
        phieu_nk(string maHang, string tenHang, string donViTinh, string ngayNhap, int soLuong, double donGia, double thanhTien){
            this->maHang = maHang;
            this->tenHang = tenHang;
            this->donViTinh = donViTinh;
            this->ngayNhap = ngayNhap;
            this->soLuong = soLuong;
            this->donGia = donGia;
            this->thanhTien = thanhTien;
        }
        void tinhThanhTien(){
                double thanhTienGoc = this->soLuong * this->donGia;

                if(this->soLuong > 200) this->thanhTien = 0.85 * thanhTienGoc;
                else if(this->soLuong <= 100) this->thanhTien = thanhTienGoc;
                else this->thanhTien = 0.9*thanhTienGoc;
        }
        friend void thongKeTheoThang(int thang);
        friend void xoaMatHang(string donVi, string maHang);

};

vector<phieu_nk *> khoPhieu(1000);

void thongKeTheoThang(int thang){
    for(int ngay = 1; ngay<= 30; ngay++){
        double tongTien = 0;
        string ngayNhap ;
        for(int i = 0; i< khoPhieu.size() ;i++){
            if(khoPhieu[i] != nullptr){
                ngayNhap = khoPhieu[i]->ngayNhap;
                if(thang == get_thang(ngayNhap) && ngay == get_ngay(ngayNhap)){

                    khoPhieu[i] ->tinhThanhTien();
                    tongTien += khoPhieu[i]->thanhTien;
                }
            }
        }

        cout << ngayNhap << "                 " << tongTien << "\n";
    }
}

void xoaMatHang(string donVi, string maHang){
    for(int i = 0; i < khoPhieu.size(); i++){
        phieu_nk *phieu = khoPhieu[i];
        if(phieu
            && phieu->donViTinh == donVi && trungMaHang(phieu->maHang, maHang)){
                delete phieu;
            }
    }
}

void menu(){
    cout << "\n========= MENU QUAN LY NHAP HANG =========" << "\n";
    cout << "1. Nhap hang moi" << "\n";
    cout << "2. Thong ke hang" << "\n";
    cout << "3. Xoa Hang ";
}
