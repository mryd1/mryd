# 学生试卷分数统计系统

## 系统功能如下
1. 系统以菜单方式工作
   具有主控界面,用户按照主控界面提示选择相应的功能;
2. 分数信息的读入与添加，查询，浏览等基本操作
   分数信息用文件保存,要求库存中已有10条以上记录;
   一个学生的情况可以考虑用一个结构体变量来表示。
   文件信息不超过100条记录,即数组长度可固定为100;
3. 必须接收总评成绩的计算比例，因为针对不同的课程，平时成绩和期末考试成绩所占的比例可能不同。
   接受学生的平时成绩和期末成绩，计算出总评成绩，总评成绩的计算方法是“平时成绩*平时成绩所占比例+期末成绩*期末成绩所占比例”。
   根据考试成绩计算分段的分布情况及百比分（也可作坐标图显示）。
   计算平时成绩、期末成绩和总评成绩的平均分和标准差，以及期末成绩的及格率、最高分和最低分等。
4. 系统其他功能模块
   根据课题适当加入相应的扩展功能,自由发挥;
5. 可参考如下试卷统计分析表
|分类|项目|不及格|60-69分|70-79分|80-89分|90-100分|平均分|标准差|
|---:|---|---|---|---|---|---|-----|---|
|平时成绩|人数|8|6|16|35|11|77.3|15.04|
|平时成绩|比例|10.53%|7.89%|21%|46%|14%|
|期末成绩|人数|20|11|14|19|12|71.5|19.11|
|期末成绩|比例|26%|14%|18%|25%|16%|
|总评成绩|人数|12|13|19|19|13|72.6|17.97|
|总评成绩|比例|16%|17%|25%|25%|17%|

> 期末考试卷面及格率：73.68%       期末考试最高分：97         期末考试最低分：28
> 
> 总评成绩=平时成绩*20%+期末成绩*80%   学生总人数：76名								



