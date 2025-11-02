#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct MayBay {
	string soHieu;
	int soCho;
};
struct KhachHang {
	int soThuTu;
	string CMND;
	string hoTen;
};
struct Ve {
	string maVe;
	string maChuyenBay;
	KhachHang thongTinKhachHang;
	string soGhe;
};
struct ChuyenBay {
	string maChuyenBay;
	string soHieuMayBay;
	string ngayKhoiHanh;
	string sanBayDen;
	string trangThai;
	list<Ve> danhSachVe;
	list<string> danhSachGheTrong;
};
struct Admin {
	string tenDangNhap;
	string matKhau;
};

void DocFileVeRieng(const string& maVe, Ve& ve) {
	string tenFile = maVe + ".txt";
	ifstream file(tenFile);
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}
	getline(file, ve.maVe);
	getline(file, ve.maChuyenBay);
	getline(file, ve.soGhe);
	file >> ve.thongTinKhachHang.soThuTu;
	file.ignore();
	getline(file, ve.thongTinKhachHang.CMND);
	getline(file, ve.thongTinKhachHang.hoTen);
	file.close();
}

void GhiFileMayBay(const vector<MayBay>& dsMayBay, const string& mayBay) {
	ofstream file("MayBay.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}
	file << dsMayBay.size() << endl;
	for (const auto& mb : dsMayBay) {
		file << mb.soHieu << endl;
		file << mb.soCho << endl;
	}
	file.close();
}

void DocFileMayBay(vector<MayBay>& dsMayBay,const string& mayBay) {
	dsMayBay.clear();
	ifstream file("MayBay.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}
	int n;
	file >> n;
	file.ignore();

	for (int i = 0; i < n; i++) {
		MayBay mb;
		getline(file, mb.soHieu);
		file >> mb.soCho;
		file.ignore();
		dsMayBay.push_back(mb);
	}
}

void GhiFileKhachHang(const vector<KhachHang>& dsKhachHang, const string& khachHang) {
	ofstream file("KhachHang.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}

	file << dsKhachHang.size() << endl;
	for (const auto& kh : dsKhachHang) {
		file << kh.soThuTu << endl;
		file << kh.CMND << endl;
		file << kh.hoTen << endl;
	}
	file.close();
}

void DocFileKhachHang(vector<KhachHang>& dsKhachHang, const string& khachHang) {
	dsKhachHang.clear();
	ifstream file("KhachHang.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}

	int n;
	file >> n;
	file.ignore();

	for (int i = 0; i < n; i++) {
		KhachHang kh;
		file >> kh.soThuTu;
		file.ignore();
		getline(file, kh.CMND);
		getline(file, kh.hoTen);
		dsKhachHang.push_back(kh);
	}
	file.close();
}

void GhiFileChuyenBay(const vector<ChuyenBay>& dsChuyenBay, const string& chuyenBay) {
	ofstream file("ChuyenBay.txt");
	file << dsChuyenBay.size() << endl;
	for (const auto& cb : dsChuyenBay) {
		file << cb.maChuyenBay << endl;
		file << cb.soHieuMayBay << endl;
		file << cb.ngayKhoiHanh << endl;
		file << cb.sanBayDen << endl;
		file << cb.trangThai << endl;

		file << cb.danhSachVe.size() << endl;
		for (const Ve& ve : cb.danhSachVe) {
			file << ve.maVe << endl;
		}

		file << cb.danhSachGheTrong.size() << endl;
		for (const auto& ghe : cb.danhSachGheTrong) {
			file << ghe << endl;
		}
	}
	file.close();
}

void DocFileChuyenBay(vector<ChuyenBay>& dsChuyenBay, const string& chuyenBay) {
	dsChuyenBay.clear();
	ifstream file("ChuyenBay.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++) {
		ChuyenBay cb;
		getline(file, cb.maChuyenBay);
		getline(file, cb.soHieuMayBay);
		getline(file, cb.ngayKhoiHanh);
		getline(file, cb.sanBayDen);
		getline(file, cb.trangThai);

		int soVe;
		file >> soVe;
		file.ignore();
		for (int j = 0; j < soVe; j++) {
			string maVe;
			Ve veMoi;
			getline(file, maVe);
			DocFileVeRieng(maVe, veMoi);
			veMoi.maVe = maVe;
			cb.danhSachVe.push_back(veMoi);
		}
		int soGhe;
		file >> soGhe;
		file.ignore();
		for (int j = 0; j < soGhe; j++) {
			string ghe;
			getline(file, ghe);
			cb.danhSachGheTrong.push_back(ghe);
		}
		dsChuyenBay.push_back(cb);
	}
	file.close();
}

void GhiFileAdmin(const vector<Admin>& dsAdmin, const string& adminFile) {
	ofstream file("Admin.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}

	file << dsAdmin.size() << endl;
	for (const auto& admin : dsAdmin) {
		file << admin.tenDangNhap << endl;
		file << admin.matKhau << endl;
	}
	file.close();
}

void DocFileAdmin(vector<Admin>& dsAdmin, const string& adminFile) {
	dsAdmin.clear();
	ifstream file("Admin.txt");
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++) {
		Admin admin;
		getline(file, admin.tenDangNhap);
		getline(file, admin.matKhau);
		dsAdmin.push_back(admin);
	}
	file.close();
}

void GhiFileVe(const Ve& ve) {
	string tenFile = ve.maVe + ".txt";
	ofstream file(tenFile);
	if (!file.is_open()) {
		cout << "File khong ton tai";
		return;
	}

	file << ve.maVe << endl;
	file << ve.maChuyenBay << endl;
	file << ve.soGhe << endl;
	file << ve.thongTinKhachHang.soThuTu << endl;
	file << ve.thongTinKhachHang.CMND << endl;
	file << ve.thongTinKhachHang.hoTen << endl;

	file.close();
}

bool SoHieuDuyNhat(const vector <MayBay>& dsMayBay, const string& soHieuMoi) {
	for (const auto& mb : dsMayBay) {
		if (mb.soHieu == soHieuMoi) {
			return false;
		}
	}
	return true;
}

bool MaDuyNhat(const vector<ChuyenBay>& dsChuyenBay, const string& maMoi) {
	for (const auto& cb : dsChuyenBay) {
		if (cb.maChuyenBay == maMoi) {
			return false;
		}
	}
	return true;
}

list<string> TaoDanhSachGheTrong(int soCho) {
	list<string> danhsachGhe;
	for (int i = 1; i <= soCho; ++i) {
		string soGhe;
		if (i < 10) {
			soGhe = "0" + to_string(i);
		}
		else {
			soGhe = to_string(i);
		}
		danhsachGhe.push_back(soGhe);
	}
	return danhsachGhe;
}

void KhoiTaoDuLieuMau() {
	vector<MayBay> dsMayBay = {
		{"VN-A101", 100},
		{"VN-B202", 50},
		{"VN-C303", 200}
	};
	GhiFileMayBay(dsMayBay, "");

	vector<KhachHang> dsKhachHang = {
		{1, "0011223344", "Nguyen Van A"},
		{2, "0022334455", "Tran Thi B"},
		{3, "0033445566", "Le Van C"},
		{4, "0044556677", "Pham Thi D"},
		{5, "0055667788", "Hoang Van E"},
		{6, "0066778899", "Dang Thi F"},
		{7, "0077889900", "Bui Van G"},
		{8, "0088990011", "Vo Thi H"},
		{9, "0099001122", "Do Van I"},
		{10, "0011223300", "Ngo Thi K"}
	};
	GhiFileKhachHang(dsKhachHang, "");

	vector<ChuyenBay> dsChuyenBay;

	ChuyenBay cb1;
	cb1.maChuyenBay = "CB001";
	cb1.soHieuMayBay = "VN-A101";
	cb1.ngayKhoiHanh = "2025-11-15";
	cb1.sanBayDen = "Ha Noi";
	cb1.trangThai = "1";

	cb1.danhSachGheTrong = TaoDanhSachGheTrong(100);

	Ve ve1;
	ve1.maChuyenBay = "CB001";
	ve1.soGhe = "01";
	ve1.thongTinKhachHang = dsKhachHang[0];
	ve1.maVe = ve1.maChuyenBay + ve1.soGhe;
	cb1.danhSachVe.push_back(ve1);
	cb1.danhSachGheTrong.remove(ve1.soGhe);
	GhiFileVe(ve1);

	Ve ve2;
	ve2.maChuyenBay = "CB001";
	ve2.soGhe = "02";
	ve2.thongTinKhachHang = dsKhachHang[1];
	ve2.maVe = ve2.maChuyenBay + ve2.soGhe;
	cb1.danhSachVe.push_back(ve2);
	cb1.danhSachGheTrong.remove(ve2.soGhe);
	GhiFileVe(ve2);

	dsChuyenBay.push_back(cb1);

	ChuyenBay cb2 = { "CB002", "VN-B202", "2025-12-01", "TP Ho Chi Minh", "1", {}, TaoDanhSachGheTrong(50) };
	dsChuyenBay.push_back(cb2);

	ChuyenBay cb3 = { "CB003", "VN-C303", "2025-12-15", "Da Nang", "2", {}, TaoDanhSachGheTrong(200) };
	dsChuyenBay.push_back(cb3);

	ChuyenBay cb4 = { "CB004", "VN-A101", "2026-01-01", "Hue", "0", {}, TaoDanhSachGheTrong(100) };
	ChuyenBay cb5 = { "CB005", "VN-B202", "2026-01-15", "Can Tho", "3", {}, {} };

	dsChuyenBay.push_back(cb4);
	dsChuyenBay.push_back(cb5);

	GhiFileChuyenBay(dsChuyenBay, "");

	vector<Admin> dsAdmin = {
		{"SonTung-MTP", "363636"}
	};
	GhiFileAdmin(dsAdmin, "");
	cout << "Khoi tao du lieu thanh cong\n";
}

int main() {
	KhoiTaoDuLieuMau();
}