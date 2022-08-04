文件
    Makefile        
    create_project.sh
    S_manage.conf
    admin.c     
    admin.h
    menu.c
    menu.h
    S_manage.c
    S_manage.h
    teacher.c
    teacher.h
    student.c
    student.h
    main.c
    score.txt       //批量录入学生成绩
    stu.txt        //批量入录学生
    S_At.txt        //学生
    T_atjob.txt     //老师
结构体
    学生
    typedef struct Student
    {
        char name[20];
        char sex;
        char id[13];
        char pwd[7];
        double Chinese;
        double Math;
        double English;
        char first; //是否初次登录
        char count;	//密码输入次数
        char flag;	//是否在校
    }Student;


    老师
    typedef struct Teacher
    {
        char name[20];
        char sex;
        char id[13];
        char pwd[7];
        char first; //是否初次登录
        char count; //密码输入次数
        char flag;  //是否在校
    } Teacher;

    校长
    typedef struct Admin
    {
        char name[20];
        char A_pwd[7];
        char first;
    } Admin;



全局变量
    extern int temp；  //标记当前登录人员（学生界面）
    extern int pos;    //标记当前登录人员（老师界面）
    extern int S_num;      //学生人数
    extern int T_num;      //老师人数
    extern int A_num;      //校长人数
    extern FILE *S_fp; //学生文件
    extern FILE *T_fp; //教师文件
    extern FILE *A_fp; //校长文件
    extern Student *stu;
    extern Teacher *tea;
    extern Admin *admin;

    函数名
    menu.h 
    void limit(int num, char secret[]);         //限制输入长度
    int limit_input(int len, char *str);       //限制中文输入长度
    void pwd_hide(int len, char *pwd);         //隐藏密码
    void msg_show(const char *msg, float sec); //提示信息
    void anykey_continue(void);                //按任意键继续
    char *int_to_string(int num);              //整型转字符串
    bool T_login(void *p, FILE *fp);           //老师登录
    bool S_login(void *p, FILE *fp);           //学生登录
    bool A_login(void *p, FILE *fp);           //校长登录
    char *encrypt(char *str);                  //加密
    char *decrypt(char *str);                  //解密
    int menu(void);                            //主菜单
    int S_menu(void);                          //学生菜单
    int T_menu(void);                          //老师菜单
    int A_menu(void);                          //校长菜单
    void A_option(void);                       //校长菜单选项
    void T_option(void);                       //老师菜单选项
    void S_option(void);                       //学生菜单选项

    S_manage.h
    void init_system(void);     //初始化
    void start_system(void);    //运行
    void end_system(void);      //保存结束

    student.h
    void init_S_pwd(void);   //初始化
    void find(void);         //查询成绩
    void S_modify_pwd(void); //修改密码
    void show(void);         //查看个人信息
    void pwd_S_error(void);  //三次密码错误锁定帐号，由教师解锁

    teacher.h
  
    void S_add(void);          //添加学生
    void S_del(void);          //删除学生
    void S_find(void);         //查找学生
    void S_modify(void);       //修改学生信息
    void enter_S_grades(void); //录入学生成绩
    void modify_S_pwd(void);   //重置学生密码
    void show_At(void);        //显示所有在校学生信息
    void show_leave(void);     //显示所有退出学生信息
    void T_modify_pwd(void);   //重置老师自己密码

    admin.h
    void init_A_pwd(void);       //初始化密码
    void modify_M_pwd(void);     //重置自己密码
    void modify_T_pwd(void);     //重置老师密码
    void T_add(void);            //添加老师
    void T_del(void);            //删除老师
    void T_A_show(void);         //显示所有在职教师
    void T_L_show(void);         //显示所有离职教师
    void Unlock_T_account(void); //解锁教师帐号

    