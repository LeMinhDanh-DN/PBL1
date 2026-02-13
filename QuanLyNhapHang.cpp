#include "QuanLyNhapHang.h"

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
    for(int i = 6; i<= 9; i++){
        year = year*10 + (date[i] -'0');
    }
    return year;
}

int checkTrungMaHang(string maGoc, string maBatDau){
    for(int i = 0; i< maBatDau.size() ; i++){
        if(maGoc[i] != maBatDau[i]) return 0;
    }
    return 1;
}

vector<phieuNhapKho *> khoPhieu;

void tinhThanhTien(phieuNhapKho *ptr){
        double thanhTienGoc = ptr->soLuong * ptr->donGia;

        if(ptr->soLuong > 200) ptr->thanhTien = 0.85 * thanhTienGoc;
        else if(ptr->soLuong <= 100) ptr->thanhTien = thanhTienGoc;
        else ptr->thanhTien = 0.9*thanhTienGoc;
}

void nhapKho(string maHang, string tenHang, string donViTinh, string ngayNhap, int soLuong, double donGia, double thanhTien){
    phieuNhapKho *newOrder = new phieuNhapKho;
    newOrder->maHang = maHang;
    newOrder->tenHang = tenHang;
    newOrder->donViTinh = donViTinh;
    newOrder->ngayNhap = ngayNhap;
    newOrder->soLuong = soLuong;
    newOrder->donGia = donGia;
    newOrder->thanhTien = thanhTien;

    khoPhieu.push_back(newOrder);
}


void thongKeTheoThang(int thang){
    for(int ngay = 1; ngay<= 30; ngay++){
        double tongTien = 0;
        string ngayNhap ;
        for(int i = 0; i< khoPhieu.size() ;i++){
            if(khoPhieu[i] != nullptr){
                ngayNhap = khoPhieu[i]->ngayNhap;
                if(thang == get_thang(ngayNhap) && ngay == get_ngay(ngayNhap)){

                    tinhThanhTien(khoPhieu[i] );
                    tongTien += khoPhieu[i]->thanhTien;
                }
            }
        }

        cout << ngayNhap << " " << tongTien << "\n";
    }
}

void xoaMatHang(string donVi, string maHang){
    for(int i = 0; i < khoPhieu.size(); i++){
        phieuNhapKho *phieu = khoPhieu[i];
        if(phieu
            && phieu->donViTinh == donVi && checkTrungMaHang(phieu->maHang, maHang)){
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