# Subtree
Demo cây đỏ đen libfdr

# Các lệnh cơ bản của Red black tree

#### Khởi tạo cây jrb
```
extern JRB make_jrb();
JRB sub=make_jrb();
```

#### Thao tác chèn
```
JRB jrb_insert_str(JRB tree, char *key, Jval val)   //chèn node mới
JRB jrb_insert_int(JRB tree, int key, Jval val)     //chèn node mới
JRB jrb_insert_dbl(JRB tree, double key, Jval val)
```
#### Chèn với kiểu jval
`JRB jrb_insert_gen(JRB tree, Jval key, Jval val, int (*func)(Jval, Jval))`
> Key với kiểu jval. Cần cung cấp `(*func)(Jval, Jval)` là một hàm so sánh lấy 2 Jval làm đối số và trả về
>   - số âm nếu khóa 1 nhỏ hơn khóa 2
>   - số dương nếu khóa 1 lớn hơn khóa 2
>   - 0 nếu 2 khóa bằng nhau

#### Tìm kiếm trong cây
```
> Trả về node có giá trị bằng key. Nếu không tìm được thì trả về NULL

extern JRB jrb_find_str(JRB root, char *key);
extern JRB jrb_find_int(JRB root, int ikey);
extern JRB jrb_find_dbl(JRB root, double dkey);
extern JRB jrb_find_gen(JRB root, Jval, int (*func)(Jval, Jval));
```
```
> Trả về node có giá trị bằng key hoặc giá trị nhỏ nhất lớn hơn key. Đặt found=1 nếu tìm thấy khóa, found=0 nếu không tìm thấy

extern JRB jrb_find_gte_str(JRB root, char *key, int *found);
extern JRB jrb_find_gte_int(JRB root, int ikey, int *found);
extern JRB jrb_find_gte_dbl(JRB root, double dkey, int *found);
extern JRB jrb_find_gte_gen(JRB root, Jval key, int (*func)(Jval, Jval), int *found);
```
#### Xóa node
`extern void jrb_delete_node(JRB node);`
> xóa và giải phóng 1 node
#### Xóa cây
`extern void jrb_free_tree(JRB root);`
> xóa và giải phóng toàn bộ cây
#### Đếm số node đen
`extern int jrb_nblack(JRB n);`
> Trả về số node đen trong đường dẫn từ n đến gốc
#### Đếm số node
`extern int jrb_nblack(JRB n);`
> Trả về số node trong đường dẫn từ n đến gốc
