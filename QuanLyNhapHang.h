#ifndef QUANLYNHAPHANG_H
#define QUANLYNHAPHANG_H

#include <iostream>
#include <vector>
using namespace std;

struct phieuNhapKho{
    string maHang;
    string tenHang;
    string donViTinh;
    string ngayNhap;
    int soLuong;
    double donGia;
    double thanhTien;

};

int get_thang(string date);
int get_ngay(string date);
int get_nam(string date);

int checkTrungMaHang(string maGoc, string maBatDau);
void tinhThanhTien(phieuNhapKho *ptr);
void nhapKho(string maHang, string tenHang, string donViTinh, string ngayNhap, int soLuong, double donGia, double thanhTien);
void thongKeTheoThang(int thang);
void xoaMatHang(string donVi, string maHang);
void menu();

#endif